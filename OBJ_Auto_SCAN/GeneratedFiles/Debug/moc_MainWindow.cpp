/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/ui/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[131];
    char stringdata0[2665];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "ShowDialog"
QT_MOC_LITERAL(2, 22, 11), // "std::string"
QT_MOC_LITERAL(3, 34, 0), // ""
QT_MOC_LITERAL(4, 35, 5), // "bool*"
QT_MOC_LITERAL(5, 41, 2), // "ok"
QT_MOC_LITERAL(6, 44, 11), // "const char*"
QT_MOC_LITERAL(7, 56, 5), // "title"
QT_MOC_LITERAL(8, 62, 5), // "label"
QT_MOC_LITERAL(9, 68, 4), // "text"
QT_MOC_LITERAL(10, 73, 16), // "UpdateViewerSlot"
QT_MOC_LITERAL(11, 90, 28), // "pcl::PointCloud<PointT>::Ptr"
QT_MOC_LITERAL(12, 119, 10), // "pointCloud"
QT_MOC_LITERAL(13, 130, 19), // "TableItemChangeSlot"
QT_MOC_LITERAL(14, 150, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(15, 168, 4), // "item"
QT_MOC_LITERAL(16, 173, 19), // "ShowInputDialogSlot"
QT_MOC_LITERAL(17, 193, 19), // "GetDialogResultSlot"
QT_MOC_LITERAL(18, 213, 4), // "minX"
QT_MOC_LITERAL(19, 218, 4), // "maxX"
QT_MOC_LITERAL(20, 223, 4), // "minY"
QT_MOC_LITERAL(21, 228, 4), // "maxY"
QT_MOC_LITERAL(22, 233, 4), // "minZ"
QT_MOC_LITERAL(23, 238, 4), // "maxZ"
QT_MOC_LITERAL(24, 243, 12), // "OpenFileSlot"
QT_MOC_LITERAL(25, 256, 12), // "SaveFileSlot"
QT_MOC_LITERAL(26, 269, 28), // "SetViewBackgroundToBlackSlot"
QT_MOC_LITERAL(27, 298, 33), // "SetViewWhiteBackgroundToWhite..."
QT_MOC_LITERAL(28, 332, 20), // "StartFlexxCameraSlot"
QT_MOC_LITERAL(29, 353, 17), // "StartRSCameraSlot"
QT_MOC_LITERAL(30, 371, 23), // "StartXtionProCameraSlot"
QT_MOC_LITERAL(31, 395, 14), // "StopCameraSlot"
QT_MOC_LITERAL(32, 410, 28), // "SetCameraDepthConfidenceSlot"
QT_MOC_LITERAL(33, 439, 20), // "GetNumberOfBytesSlot"
QT_MOC_LITERAL(34, 460, 11), // "GetCharSlot"
QT_MOC_LITERAL(35, 472, 12), // "GetArraySlot"
QT_MOC_LITERAL(36, 485, 16), // "ControlMotorSlot"
QT_MOC_LITERAL(37, 502, 16), // "KeepOneFrameSlot"
QT_MOC_LITERAL(38, 519, 21), // "KeepContinueFrameSlot"
QT_MOC_LITERAL(39, 541, 20), // "KeepFrameArrivedSlot"
QT_MOC_LITERAL(40, 562, 28), // "RemoveSelectedPointCloudSlot"
QT_MOC_LITERAL(41, 591, 23), // "RemoveAllPointCloudSlot"
QT_MOC_LITERAL(42, 615, 23), // "SelectAllPointCloudSlot"
QT_MOC_LITERAL(43, 639, 25), // "UnselectAllPointCloudSlot"
QT_MOC_LITERAL(44, 665, 21), // "CombinePointCloudSlot"
QT_MOC_LITERAL(45, 687, 24), // "GetMinNegativeNumberSlot"
QT_MOC_LITERAL(46, 712, 15), // "ProcessICP1Slot"
QT_MOC_LITERAL(47, 728, 15), // "ProcessICP2Slot"
QT_MOC_LITERAL(48, 744, 15), // "ProcessICP3Slot"
QT_MOC_LITERAL(49, 760, 19), // "ShiftPointCloudSlot"
QT_MOC_LITERAL(50, 780, 28), // "MultiplicationPointCloudSlot"
QT_MOC_LITERAL(51, 809, 13), // "RemoveNANSlot"
QT_MOC_LITERAL(52, 823, 19), // "ProcessKeypointSlot"
QT_MOC_LITERAL(53, 843, 21), // "ChangeKeypointTabSlot"
QT_MOC_LITERAL(54, 865, 5), // "index"
QT_MOC_LITERAL(55, 871, 21), // "SetKeypointScalesSlot"
QT_MOC_LITERAL(56, 893, 26), // "SetKeypointMinContrastSlot"
QT_MOC_LITERAL(57, 920, 21), // "SetKeypointRadiusSlot"
QT_MOC_LITERAL(58, 942, 27), // "SetKeypointRadiusSearchSlot"
QT_MOC_LITERAL(59, 970, 21), // "SetKeypointMethodSlot"
QT_MOC_LITERAL(60, 992, 19), // "ChangeFilterTabSlot"
QT_MOC_LITERAL(61, 1012, 17), // "ProcessFilterSlot"
QT_MOC_LITERAL(62, 1030, 25), // "SetFilterVoxelGridXYZSlot"
QT_MOC_LITERAL(63, 1056, 24), // "SetFilterBoundingBoxSlot"
QT_MOC_LITERAL(64, 1081, 18), // "SetFilterMeanKSlot"
QT_MOC_LITERAL(65, 1100, 5), // "meanK"
QT_MOC_LITERAL(66, 1106, 28), // "SetFilterStddevMulThreshSlot"
QT_MOC_LITERAL(67, 1135, 15), // "stddevMulThresh"
QT_MOC_LITERAL(68, 1151, 19), // "TestBoundingBoxSlot"
QT_MOC_LITERAL(69, 1171, 28), // "ChangeCorrespondencesTabSlot"
QT_MOC_LITERAL(70, 1200, 26), // "ProcessCorrespondencesSlot"
QT_MOC_LITERAL(71, 1227, 37), // "SetCorrespondenceDescriptorRa..."
QT_MOC_LITERAL(72, 1265, 16), // "descriptorRadius"
QT_MOC_LITERAL(73, 1282, 45), // "SetCorrespondenceDescriptorKS..."
QT_MOC_LITERAL(74, 1328, 7), // "kSearch"
QT_MOC_LITERAL(75, 1336, 33), // "SetCorrespondenceNormalRadius..."
QT_MOC_LITERAL(76, 1370, 12), // "normalRadius"
QT_MOC_LITERAL(77, 1383, 23), // "SetCorrespondencesKSlot"
QT_MOC_LITERAL(78, 1407, 16), // "correspondencesK"
QT_MOC_LITERAL(79, 1424, 30), // "SetRejectorInlierThresholdSlot"
QT_MOC_LITERAL(80, 1455, 23), // "rejectorInlierThreshold"
QT_MOC_LITERAL(81, 1479, 23), // "ProcessRegestrationSlot"
QT_MOC_LITERAL(82, 1503, 41), // "SetRegestrationCorrespondence..."
QT_MOC_LITERAL(83, 1545, 22), // "correspondenceDistance"
QT_MOC_LITERAL(84, 1568, 35), // "SetRegestrationOutlierThresho..."
QT_MOC_LITERAL(85, 1604, 16), // "outlierThreshold"
QT_MOC_LITERAL(86, 1621, 30), // "SetEuclideanFitnessEpsilonSlot"
QT_MOC_LITERAL(87, 1652, 23), // "euclideanFitnessEpsilon"
QT_MOC_LITERAL(88, 1676, 32), // "SetRegestrationMaxIterationsSlot"
QT_MOC_LITERAL(89, 1709, 13), // "maxIterations"
QT_MOC_LITERAL(90, 1723, 24), // "ChangeReconstructTabSlot"
QT_MOC_LITERAL(91, 1748, 22), // "ProcessReconstructSlot"
QT_MOC_LITERAL(92, 1771, 30), // "SetReconstructSearchRadiusSlot"
QT_MOC_LITERAL(93, 1802, 12), // "searchRadius"
QT_MOC_LITERAL(94, 1815, 20), // "SetReconstructMuSlot"
QT_MOC_LITERAL(95, 1836, 2), // "mu"
QT_MOC_LITERAL(96, 1839, 37), // "SetReconstructMaxNearestNeigh..."
QT_MOC_LITERAL(97, 1877, 19), // "maxNearestNeighbors"
QT_MOC_LITERAL(98, 1897, 33), // "SetReconstructMaxSurfaceAngle..."
QT_MOC_LITERAL(99, 1931, 15), // "maxSurfaceAngle"
QT_MOC_LITERAL(100, 1947, 26), // "SetReconstructMinAngleSlot"
QT_MOC_LITERAL(101, 1974, 8), // "minAngle"
QT_MOC_LITERAL(102, 1983, 26), // "SetReconstructMaxAngleSlot"
QT_MOC_LITERAL(103, 2010, 8), // "maxAngle"
QT_MOC_LITERAL(104, 2019, 35), // "SetReconstructGridResolutionX..."
QT_MOC_LITERAL(105, 2055, 26), // "SetReconstructIsoLevelSlot"
QT_MOC_LITERAL(106, 2082, 8), // "isoLevel"
QT_MOC_LITERAL(107, 2091, 36), // "SetReconstructNormalSearchRad..."
QT_MOC_LITERAL(108, 2128, 18), // "normalSearchRadius"
QT_MOC_LITERAL(109, 2147, 23), // "SetReconstructDepthSlot"
QT_MOC_LITERAL(110, 2171, 23), // "SetReconstructAlphaSlot"
QT_MOC_LITERAL(111, 2195, 22), // "ChangeSmoothingTabSlot"
QT_MOC_LITERAL(112, 2218, 20), // "ProcessSmoothingSlot"
QT_MOC_LITERAL(113, 2239, 23), // "SetSmoothingNumIterSlot"
QT_MOC_LITERAL(114, 2263, 7), // "numIter"
QT_MOC_LITERAL(115, 2271, 27), // "SetSmoothingConvergenceSlot"
QT_MOC_LITERAL(116, 2299, 11), // "convergence"
QT_MOC_LITERAL(117, 2311, 40), // "SetSmoothingRelaxationFactorM..."
QT_MOC_LITERAL(118, 2352, 16), // "relaxationFactor"
QT_MOC_LITERAL(119, 2369, 28), // "SetSmoothingFeatureAngleSlot"
QT_MOC_LITERAL(120, 2398, 12), // "featureAngle"
QT_MOC_LITERAL(121, 2411, 28), // "SetSmoothingSearchRadiusSlot"
QT_MOC_LITERAL(122, 2440, 31), // "ProcessKinfuTestBoundingBoxSlot"
QT_MOC_LITERAL(123, 2472, 27), // "GetKinfuTestBoundingBoxSlot"
QT_MOC_LITERAL(124, 2500, 30), // "ProcessSegmentedKinfuCloudSlot"
QT_MOC_LITERAL(125, 2531, 32), // "ProcessIgnoreResetKinfuCloudSlot"
QT_MOC_LITERAL(126, 2564, 12), // "SaveRTMatrix"
QT_MOC_LITERAL(127, 2577, 54), // "std::vector<Eigen::Matrix<flo..."
QT_MOC_LITERAL(128, 2632, 1), // "r"
QT_MOC_LITERAL(129, 2634, 28), // "std::vector<Eigen::Vector3f>"
QT_MOC_LITERAL(130, 2663, 1) // "t"

    },
    "MainWindow\0ShowDialog\0std::string\0\0"
    "bool*\0ok\0const char*\0title\0label\0text\0"
    "UpdateViewerSlot\0pcl::PointCloud<PointT>::Ptr\0"
    "pointCloud\0TableItemChangeSlot\0"
    "QTableWidgetItem*\0item\0ShowInputDialogSlot\0"
    "GetDialogResultSlot\0minX\0maxX\0minY\0"
    "maxY\0minZ\0maxZ\0OpenFileSlot\0SaveFileSlot\0"
    "SetViewBackgroundToBlackSlot\0"
    "SetViewWhiteBackgroundToWhiteSlot\0"
    "StartFlexxCameraSlot\0StartRSCameraSlot\0"
    "StartXtionProCameraSlot\0StopCameraSlot\0"
    "SetCameraDepthConfidenceSlot\0"
    "GetNumberOfBytesSlot\0GetCharSlot\0"
    "GetArraySlot\0ControlMotorSlot\0"
    "KeepOneFrameSlot\0KeepContinueFrameSlot\0"
    "KeepFrameArrivedSlot\0RemoveSelectedPointCloudSlot\0"
    "RemoveAllPointCloudSlot\0SelectAllPointCloudSlot\0"
    "UnselectAllPointCloudSlot\0"
    "CombinePointCloudSlot\0GetMinNegativeNumberSlot\0"
    "ProcessICP1Slot\0ProcessICP2Slot\0"
    "ProcessICP3Slot\0ShiftPointCloudSlot\0"
    "MultiplicationPointCloudSlot\0RemoveNANSlot\0"
    "ProcessKeypointSlot\0ChangeKeypointTabSlot\0"
    "index\0SetKeypointScalesSlot\0"
    "SetKeypointMinContrastSlot\0"
    "SetKeypointRadiusSlot\0SetKeypointRadiusSearchSlot\0"
    "SetKeypointMethodSlot\0ChangeFilterTabSlot\0"
    "ProcessFilterSlot\0SetFilterVoxelGridXYZSlot\0"
    "SetFilterBoundingBoxSlot\0SetFilterMeanKSlot\0"
    "meanK\0SetFilterStddevMulThreshSlot\0"
    "stddevMulThresh\0TestBoundingBoxSlot\0"
    "ChangeCorrespondencesTabSlot\0"
    "ProcessCorrespondencesSlot\0"
    "SetCorrespondenceDescriptorRadiusSlot\0"
    "descriptorRadius\0"
    "SetCorrespondenceDescriptorKSearchSpinBoxSlot\0"
    "kSearch\0SetCorrespondenceNormalRadiusSlot\0"
    "normalRadius\0SetCorrespondencesKSlot\0"
    "correspondencesK\0SetRejectorInlierThresholdSlot\0"
    "rejectorInlierThreshold\0ProcessRegestrationSlot\0"
    "SetRegestrationCorrespondenceDistanceSlot\0"
    "correspondenceDistance\0"
    "SetRegestrationOutlierThresholdSlot\0"
    "outlierThreshold\0SetEuclideanFitnessEpsilonSlot\0"
    "euclideanFitnessEpsilon\0"
    "SetRegestrationMaxIterationsSlot\0"
    "maxIterations\0ChangeReconstructTabSlot\0"
    "ProcessReconstructSlot\0"
    "SetReconstructSearchRadiusSlot\0"
    "searchRadius\0SetReconstructMuSlot\0mu\0"
    "SetReconstructMaxNearestNeighborsSlot\0"
    "maxNearestNeighbors\0"
    "SetReconstructMaxSurfaceAngleSlot\0"
    "maxSurfaceAngle\0SetReconstructMinAngleSlot\0"
    "minAngle\0SetReconstructMaxAngleSlot\0"
    "maxAngle\0SetReconstructGridResolutionXYZSlot\0"
    "SetReconstructIsoLevelSlot\0isoLevel\0"
    "SetReconstructNormalSearchRadiusSlot\0"
    "normalSearchRadius\0SetReconstructDepthSlot\0"
    "SetReconstructAlphaSlot\0ChangeSmoothingTabSlot\0"
    "ProcessSmoothingSlot\0SetSmoothingNumIterSlot\0"
    "numIter\0SetSmoothingConvergenceSlot\0"
    "convergence\0SetSmoothingRelaxationFactorMaxAngleSlot\0"
    "relaxationFactor\0SetSmoothingFeatureAngleSlot\0"
    "featureAngle\0SetSmoothingSearchRadiusSlot\0"
    "ProcessKinfuTestBoundingBoxSlot\0"
    "GetKinfuTestBoundingBoxSlot\0"
    "ProcessSegmentedKinfuCloudSlot\0"
    "ProcessIgnoreResetKinfuCloudSlot\0"
    "SaveRTMatrix\0"
    "std::vector<Eigen::Matrix<float,3,3,Eigen::RowMajor> >\0"
    "r\0std::vector<Eigen::Vector3f>\0t"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      90,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  464,    3, 0x06 /* Public */,
       1,    3,  473,    3, 0x26 /* Public | MethodCloned */,
       1,    2,  480,    3, 0x26 /* Public | MethodCloned */,
       1,    1,  485,    3, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  488,    3, 0x0a /* Public */,
      13,    1,  491,    3, 0x0a /* Public */,
      16,    4,  494,    3, 0x0a /* Public */,
      16,    3,  503,    3, 0x2a /* Public | MethodCloned */,
      16,    2,  510,    3, 0x2a /* Public | MethodCloned */,
      16,    1,  515,    3, 0x2a /* Public | MethodCloned */,
      17,    6,  518,    3, 0x0a /* Public */,
      24,    0,  531,    3, 0x0a /* Public */,
      25,    0,  532,    3, 0x0a /* Public */,
      26,    0,  533,    3, 0x0a /* Public */,
      27,    0,  534,    3, 0x0a /* Public */,
      28,    0,  535,    3, 0x0a /* Public */,
      29,    0,  536,    3, 0x0a /* Public */,
      30,    0,  537,    3, 0x0a /* Public */,
      31,    0,  538,    3, 0x0a /* Public */,
      32,    0,  539,    3, 0x0a /* Public */,
      33,    0,  540,    3, 0x0a /* Public */,
      34,    0,  541,    3, 0x0a /* Public */,
      35,    0,  542,    3, 0x0a /* Public */,
      36,    0,  543,    3, 0x0a /* Public */,
      37,    0,  544,    3, 0x0a /* Public */,
      38,    0,  545,    3, 0x0a /* Public */,
      39,    1,  546,    3, 0x0a /* Public */,
      40,    0,  549,    3, 0x0a /* Public */,
      41,    0,  550,    3, 0x0a /* Public */,
      42,    0,  551,    3, 0x0a /* Public */,
      43,    0,  552,    3, 0x0a /* Public */,
      44,    0,  553,    3, 0x0a /* Public */,
      45,    0,  554,    3, 0x0a /* Public */,
      46,    0,  555,    3, 0x0a /* Public */,
      47,    0,  556,    3, 0x0a /* Public */,
      48,    0,  557,    3, 0x0a /* Public */,
      49,    0,  558,    3, 0x0a /* Public */,
      50,    0,  559,    3, 0x0a /* Public */,
      51,    0,  560,    3, 0x0a /* Public */,
      52,    0,  561,    3, 0x0a /* Public */,
      53,    1,  562,    3, 0x0a /* Public */,
      55,    0,  565,    3, 0x0a /* Public */,
      56,    0,  566,    3, 0x0a /* Public */,
      57,    0,  567,    3, 0x0a /* Public */,
      58,    0,  568,    3, 0x0a /* Public */,
      59,    1,  569,    3, 0x0a /* Public */,
      60,    1,  572,    3, 0x0a /* Public */,
      61,    0,  575,    3, 0x0a /* Public */,
      62,    0,  576,    3, 0x0a /* Public */,
      63,    0,  577,    3, 0x0a /* Public */,
      64,    1,  578,    3, 0x0a /* Public */,
      66,    1,  581,    3, 0x0a /* Public */,
      68,    0,  584,    3, 0x0a /* Public */,
      69,    1,  585,    3, 0x0a /* Public */,
      70,    0,  588,    3, 0x0a /* Public */,
      71,    1,  589,    3, 0x0a /* Public */,
      73,    1,  592,    3, 0x0a /* Public */,
      75,    1,  595,    3, 0x0a /* Public */,
      77,    1,  598,    3, 0x0a /* Public */,
      79,    1,  601,    3, 0x0a /* Public */,
      81,    0,  604,    3, 0x0a /* Public */,
      82,    1,  605,    3, 0x0a /* Public */,
      84,    1,  608,    3, 0x0a /* Public */,
      86,    1,  611,    3, 0x0a /* Public */,
      88,    1,  614,    3, 0x0a /* Public */,
      90,    1,  617,    3, 0x0a /* Public */,
      91,    0,  620,    3, 0x0a /* Public */,
      92,    1,  621,    3, 0x0a /* Public */,
      94,    1,  624,    3, 0x0a /* Public */,
      96,    1,  627,    3, 0x0a /* Public */,
      98,    1,  630,    3, 0x0a /* Public */,
     100,    1,  633,    3, 0x0a /* Public */,
     102,    1,  636,    3, 0x0a /* Public */,
     104,    0,  639,    3, 0x0a /* Public */,
     105,    1,  640,    3, 0x0a /* Public */,
     107,    1,  643,    3, 0x0a /* Public */,
     109,    1,  646,    3, 0x0a /* Public */,
     110,    1,  649,    3, 0x0a /* Public */,
     111,    1,  652,    3, 0x0a /* Public */,
     112,    0,  655,    3, 0x0a /* Public */,
     113,    1,  656,    3, 0x0a /* Public */,
     115,    1,  659,    3, 0x0a /* Public */,
     117,    1,  662,    3, 0x0a /* Public */,
     119,    1,  665,    3, 0x0a /* Public */,
     121,    1,  668,    3, 0x0a /* Public */,
     122,    0,  671,    3, 0x0a /* Public */,
     123,    0,  672,    3, 0x0a /* Public */,
     124,    0,  673,    3, 0x0a /* Public */,
     125,    0,  674,    3, 0x0a /* Public */,
     126,    2,  675,    3, 0x0a /* Public */,

 // signals: parameters
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6,    5,    7,    8,    9,
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 6,    5,    7,    8,
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    0x80000000 | 2, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6,    5,    7,    8,    9,
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 6,    5,    7,    8,
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    0x80000000 | 2, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   18,   19,   20,   21,   22,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   65,
    QMetaType::Void, QMetaType::Double,   67,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   72,
    QMetaType::Void, QMetaType::Int,   74,
    QMetaType::Void, QMetaType::Double,   76,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void, QMetaType::Double,   80,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   83,
    QMetaType::Void, QMetaType::Double,   85,
    QMetaType::Void, QMetaType::Double,   87,
    QMetaType::Void, QMetaType::Int,   89,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   93,
    QMetaType::Void, QMetaType::Double,   95,
    QMetaType::Void, QMetaType::Int,   97,
    QMetaType::Void, QMetaType::Int,   99,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Int,  103,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,  106,
    QMetaType::Void, QMetaType::Double,  108,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  114,
    QMetaType::Void, QMetaType::Double,  116,
    QMetaType::Void, QMetaType::Double,  118,
    QMetaType::Void, QMetaType::Int,  120,
    QMetaType::Void, QMetaType::Double,   93,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 127, 0x80000000 | 129,  128,  130,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { std::string _r = _t->ShowDialog((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])),(*reinterpret_cast< const char*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 1: { std::string _r = _t->ShowDialog((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 2: { std::string _r = _t->ShowDialog((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 3: { std::string _r = _t->ShowDialog((*reinterpret_cast< bool*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->UpdateViewerSlot((*reinterpret_cast< pcl::PointCloud<PointT>::Ptr(*)>(_a[1]))); break;
        case 5: _t->TableItemChangeSlot((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 6: { std::string _r = _t->ShowInputDialogSlot((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])),(*reinterpret_cast< const char*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 7: { std::string _r = _t->ShowInputDialogSlot((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 8: { std::string _r = _t->ShowInputDialogSlot((*reinterpret_cast< bool*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 9: { std::string _r = _t->ShowInputDialogSlot((*reinterpret_cast< bool*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->GetDialogResultSlot((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6]))); break;
        case 11: _t->OpenFileSlot(); break;
        case 12: _t->SaveFileSlot(); break;
        case 13: _t->SetViewBackgroundToBlackSlot(); break;
        case 14: _t->SetViewWhiteBackgroundToWhiteSlot(); break;
        case 15: _t->StartFlexxCameraSlot(); break;
        case 16: _t->StartRSCameraSlot(); break;
        case 17: _t->StartXtionProCameraSlot(); break;
        case 18: _t->StopCameraSlot(); break;
        case 19: _t->SetCameraDepthConfidenceSlot(); break;
        case 20: _t->GetNumberOfBytesSlot(); break;
        case 21: _t->GetCharSlot(); break;
        case 22: _t->GetArraySlot(); break;
        case 23: _t->ControlMotorSlot(); break;
        case 24: _t->KeepOneFrameSlot(); break;
        case 25: _t->KeepContinueFrameSlot(); break;
        case 26: _t->KeepFrameArrivedSlot((*reinterpret_cast< pcl::PointCloud<PointT>::Ptr(*)>(_a[1]))); break;
        case 27: _t->RemoveSelectedPointCloudSlot(); break;
        case 28: _t->RemoveAllPointCloudSlot(); break;
        case 29: _t->SelectAllPointCloudSlot(); break;
        case 30: _t->UnselectAllPointCloudSlot(); break;
        case 31: _t->CombinePointCloudSlot(); break;
        case 32: _t->GetMinNegativeNumberSlot(); break;
        case 33: _t->ProcessICP1Slot(); break;
        case 34: _t->ProcessICP2Slot(); break;
        case 35: _t->ProcessICP3Slot(); break;
        case 36: _t->ShiftPointCloudSlot(); break;
        case 37: _t->MultiplicationPointCloudSlot(); break;
        case 38: _t->RemoveNANSlot(); break;
        case 39: _t->ProcessKeypointSlot(); break;
        case 40: _t->ChangeKeypointTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->SetKeypointScalesSlot(); break;
        case 42: _t->SetKeypointMinContrastSlot(); break;
        case 43: _t->SetKeypointRadiusSlot(); break;
        case 44: _t->SetKeypointRadiusSearchSlot(); break;
        case 45: _t->SetKeypointMethodSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->ChangeFilterTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->ProcessFilterSlot(); break;
        case 48: _t->SetFilterVoxelGridXYZSlot(); break;
        case 49: _t->SetFilterBoundingBoxSlot(); break;
        case 50: _t->SetFilterMeanKSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: _t->SetFilterStddevMulThreshSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 52: _t->TestBoundingBoxSlot(); break;
        case 53: _t->ChangeCorrespondencesTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->ProcessCorrespondencesSlot(); break;
        case 55: _t->SetCorrespondenceDescriptorRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 56: _t->SetCorrespondenceDescriptorKSearchSpinBoxSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->SetCorrespondenceNormalRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 58: _t->SetCorrespondencesKSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->SetRejectorInlierThresholdSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 60: _t->ProcessRegestrationSlot(); break;
        case 61: _t->SetRegestrationCorrespondenceDistanceSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 62: _t->SetRegestrationOutlierThresholdSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 63: _t->SetEuclideanFitnessEpsilonSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 64: _t->SetRegestrationMaxIterationsSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: _t->ChangeReconstructTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: _t->ProcessReconstructSlot(); break;
        case 67: _t->SetReconstructSearchRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 68: _t->SetReconstructMuSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 69: _t->SetReconstructMaxNearestNeighborsSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 70: _t->SetReconstructMaxSurfaceAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: _t->SetReconstructMinAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 72: _t->SetReconstructMaxAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 73: _t->SetReconstructGridResolutionXYZSlot(); break;
        case 74: _t->SetReconstructIsoLevelSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 75: _t->SetReconstructNormalSearchRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 76: _t->SetReconstructDepthSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 77: _t->SetReconstructAlphaSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 78: _t->ChangeSmoothingTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 79: _t->ProcessSmoothingSlot(); break;
        case 80: _t->SetSmoothingNumIterSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 81: _t->SetSmoothingConvergenceSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 82: _t->SetSmoothingRelaxationFactorMaxAngleSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 83: _t->SetSmoothingFeatureAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 84: _t->SetSmoothingSearchRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 85: _t->ProcessKinfuTestBoundingBoxSlot(); break;
        case 86: _t->GetKinfuTestBoundingBoxSlot(); break;
        case 87: _t->ProcessSegmentedKinfuCloudSlot(); break;
        case 88: _t->ProcessIgnoreResetKinfuCloudSlot(); break;
        case 89: _t->SaveRTMatrix((*reinterpret_cast< std::vector<Eigen::Matrix<float,3,3,Eigen::RowMajor> >(*)>(_a[1])),(*reinterpret_cast< std::vector<Eigen::Vector3f>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pcl::PointCloud<PointT>::Ptr >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pcl::PointCloud<PointT>::Ptr >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef std::string (MainWindow::*_t)(bool * , const char * , const char * , const char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::ShowDialog)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 90)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 90;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 90)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 90;
    }
    return _id;
}

// SIGNAL 0
std::string MainWindow::ShowDialog(bool * _t1, const char * _t2, const char * _t3, const char * _t4)
{
    std::string _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
