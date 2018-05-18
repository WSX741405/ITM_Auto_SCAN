#ifndef SAMPLED_SCOPE_TIME
#define SAMPLED_SCOPE_TIME

#include "kinfuApp/KinfuCommon.h"

struct SampledScopeTime : public pcl::StopWatch
{
	enum { EACH = 33 };
	SampledScopeTime(int& time_ms) : time_ms_(time_ms) {}
	~SampledScopeTime()
	{
		static int i_ = 0;
		static boost::posix_time::ptime starttime_ = boost::posix_time::microsec_clock::local_time();
		time_ms_ += getTime();
		if (i_ % EACH == 0 && i_)
		{
			boost::posix_time::ptime endtime_ = boost::posix_time::microsec_clock::local_time();
			std::cout << "Average frame time = " << time_ms_ / EACH << "ms ( " << 1000.f * EACH / time_ms_ << "fps )"
				<< "( real: " << 1000.f * EACH / (endtime_ - starttime_).total_milliseconds() << "fps )" << std::endl;
			time_ms_ = 0;
			starttime_ = endtime_;
		}
		++i_;
	}
private:
	int& time_ms_;
};

#endif