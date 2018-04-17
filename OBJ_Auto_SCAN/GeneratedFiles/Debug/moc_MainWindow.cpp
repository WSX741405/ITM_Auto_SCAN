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
    QByteArrayData data[103];
    char stringdata0[2133];
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
QT_MOC_LITERAL(17, 193, 12), // "OpenFileSlot"
QT_MOC_LITERAL(18, 206, 12), // "SaveFileSlot"
QT_MOC_LITERAL(19, 219, 20), // "StartFlexxCameraSlot"
QT_MOC_LITERAL(20, 240, 17), // "StartRSCameraSlot"
QT_MOC_LITERAL(21, 258, 14), // "StopCameraSlot"
QT_MOC_LITERAL(22, 273, 28), // "SetCameraDepthConfidenceSlot"
QT_MOC_LITERAL(23, 302, 20), // "GetNumberOfBytesSlot"
QT_MOC_LITERAL(24, 323, 11), // "GetCharSlot"
QT_MOC_LITERAL(25, 335, 12), // "GetArraySlot"
QT_MOC_LITERAL(26, 348, 16), // "ControlMotorSlot"
QT_MOC_LITERAL(27, 365, 16), // "KeepOneFrameSlot"
QT_MOC_LITERAL(28, 382, 21), // "KeepContinueFrameSlot"
QT_MOC_LITERAL(29, 404, 20), // "KeepFrameArrivedSlot"
QT_MOC_LITERAL(30, 425, 28), // "RemoveSelectedPointCloudSlot"
QT_MOC_LITERAL(31, 454, 23), // "RemoveAllPointCloudSlot"
QT_MOC_LITERAL(32, 478, 23), // "SelectAllPointCloudSlot"
QT_MOC_LITERAL(33, 502, 25), // "UnselectAllPointCloudSlot"
QT_MOC_LITERAL(34, 528, 23), // "ProcessKeypoint2ICPSlot"
QT_MOC_LITERAL(35, 552, 19), // "ProcessKeypointSlot"
QT_MOC_LITERAL(36, 572, 21), // "ChangeKeypointTabSlot"
QT_MOC_LITERAL(37, 594, 5), // "index"
QT_MOC_LITERAL(38, 600, 21), // "SetKeypointScalesSlot"
QT_MOC_LITERAL(39, 622, 26), // "SetKeypointMinContrastSlot"
QT_MOC_LITERAL(40, 649, 21), // "SetKeypointRadiusSlot"
QT_MOC_LITERAL(41, 671, 27), // "SetKeypointRadiusSearchSlot"
QT_MOC_LITERAL(42, 699, 21), // "SetKeypointMethodSlot"
QT_MOC_LITERAL(43, 721, 19), // "ChangeFilterTabSlot"
QT_MOC_LITERAL(44, 741, 17), // "ProcessFilterSlot"
QT_MOC_LITERAL(45, 759, 25), // "SetFilterVoxelGridXYZSlot"
QT_MOC_LITERAL(46, 785, 24), // "SetFilterBoundingBoxSlot"
QT_MOC_LITERAL(47, 810, 18), // "SetFilterMeanKSlot"
QT_MOC_LITERAL(48, 829, 5), // "meanK"
QT_MOC_LITERAL(49, 835, 28), // "SetFilterStddevMulThreshSlot"
QT_MOC_LITERAL(50, 864, 15), // "stddevMulThresh"
QT_MOC_LITERAL(51, 880, 28), // "ChangeCorrespondencesTabSlot"
QT_MOC_LITERAL(52, 909, 26), // "ProcessCorrespondencesSlot"
QT_MOC_LITERAL(53, 936, 37), // "SetCorrespondenceDescriptorRa..."
QT_MOC_LITERAL(54, 974, 16), // "descriptorRadius"
QT_MOC_LITERAL(55, 991, 45), // "SetCorrespondenceDescriptorKS..."
QT_MOC_LITERAL(56, 1037, 7), // "kSearch"
QT_MOC_LITERAL(57, 1045, 33), // "SetCorrespondenceNormalRadius..."
QT_MOC_LITERAL(58, 1079, 12), // "normalRadius"
QT_MOC_LITERAL(59, 1092, 23), // "SetCorrespondencesKSlot"
QT_MOC_LITERAL(60, 1116, 16), // "correspondencesK"
QT_MOC_LITERAL(61, 1133, 30), // "SetRejectorInlierThresholdSlot"
QT_MOC_LITERAL(62, 1164, 23), // "rejectorInlierThreshold"
QT_MOC_LITERAL(63, 1188, 23), // "ProcessRegestrationSlot"
QT_MOC_LITERAL(64, 1212, 41), // "SetRegestrationCorrespondence..."
QT_MOC_LITERAL(65, 1254, 22), // "correspondenceDistance"
QT_MOC_LITERAL(66, 1277, 35), // "SetRegestrationOutlierThresho..."
QT_MOC_LITERAL(67, 1313, 16), // "outlierThreshold"
QT_MOC_LITERAL(68, 1330, 40), // "SetRegestrationTransformation..."
QT_MOC_LITERAL(69, 1371, 21), // "transformationEpsilon"
QT_MOC_LITERAL(70, 1393, 32), // "SetRegestrationMaxIterationsSlot"
QT_MOC_LITERAL(71, 1426, 13), // "maxIterations"
QT_MOC_LITERAL(72, 1440, 24), // "ChangeReconstructTabSlot"
QT_MOC_LITERAL(73, 1465, 22), // "ProcessReconstructSlot"
QT_MOC_LITERAL(74, 1488, 30), // "SetReconstructSearchRadiusSlot"
QT_MOC_LITERAL(75, 1519, 12), // "searchRadius"
QT_MOC_LITERAL(76, 1532, 20), // "SetReconstructMuSlot"
QT_MOC_LITERAL(77, 1553, 2), // "mu"
QT_MOC_LITERAL(78, 1556, 37), // "SetReconstructMaxNearestNeigh..."
QT_MOC_LITERAL(79, 1594, 19), // "maxNearestNeighbors"
QT_MOC_LITERAL(80, 1614, 33), // "SetReconstructMaxSurfaceAngle..."
QT_MOC_LITERAL(81, 1648, 15), // "maxSurfaceAngle"
QT_MOC_LITERAL(82, 1664, 26), // "SetReconstructMinAngleSlot"
QT_MOC_LITERAL(83, 1691, 8), // "minAngle"
QT_MOC_LITERAL(84, 1700, 26), // "SetReconstructMaxAngleSlot"
QT_MOC_LITERAL(85, 1727, 8), // "maxAngle"
QT_MOC_LITERAL(86, 1736, 35), // "SetReconstructGridResolutionX..."
QT_MOC_LITERAL(87, 1772, 26), // "SetReconstructIsoLevelSlot"
QT_MOC_LITERAL(88, 1799, 8), // "isoLevel"
QT_MOC_LITERAL(89, 1808, 36), // "SetReconstructNormalSearchRad..."
QT_MOC_LITERAL(90, 1845, 18), // "normalSearchRadius"
QT_MOC_LITERAL(91, 1864, 23), // "SetReconstructDepthSlot"
QT_MOC_LITERAL(92, 1888, 22), // "ChangeSmoothingTabSlot"
QT_MOC_LITERAL(93, 1911, 20), // "ProcessSmoothingSlot"
QT_MOC_LITERAL(94, 1932, 23), // "SetSmoothingNumIterSlot"
QT_MOC_LITERAL(95, 1956, 7), // "numIter"
QT_MOC_LITERAL(96, 1964, 27), // "SetSmoothingConvergenceSlot"
QT_MOC_LITERAL(97, 1992, 11), // "convergence"
QT_MOC_LITERAL(98, 2004, 40), // "SetSmoothingRelaxationFactorM..."
QT_MOC_LITERAL(99, 2045, 16), // "relaxationFactor"
QT_MOC_LITERAL(100, 2062, 28), // "SetSmoothingFeatureAngleSlot"
QT_MOC_LITERAL(101, 2091, 12), // "featureAngle"
QT_MOC_LITERAL(102, 2104, 28) // "SetSmoothingSearchRadiusSlot"

    },
    "MainWindow\0ShowDialog\0std::string\0\0"
    "bool*\0ok\0const char*\0title\0label\0text\0"
    "UpdateViewerSlot\0pcl::PointCloud<PointT>::Ptr\0"
    "pointCloud\0TableItemChangeSlot\0"
    "QTableWidgetItem*\0item\0ShowInputDialogSlot\0"
    "OpenFileSlot\0SaveFileSlot\0"
    "StartFlexxCameraSlot\0StartRSCameraSlot\0"
    "StopCameraSlot\0SetCameraDepthConfidenceSlot\0"
    "GetNumberOfBytesSlot\0GetCharSlot\0"
    "GetArraySlot\0ControlMotorSlot\0"
    "KeepOneFrameSlot\0KeepContinueFrameSlot\0"
    "KeepFrameArrivedSlot\0RemoveSelectedPointCloudSlot\0"
    "RemoveAllPointCloudSlot\0SelectAllPointCloudSlot\0"
    "UnselectAllPointCloudSlot\0"
    "ProcessKeypoint2ICPSlot\0ProcessKeypointSlot\0"
    "ChangeKeypointTabSlot\0index\0"
    "SetKeypointScalesSlot\0SetKeypointMinContrastSlot\0"
    "SetKeypointRadiusSlot\0SetKeypointRadiusSearchSlot\0"
    "SetKeypointMethodSlot\0ChangeFilterTabSlot\0"
    "ProcessFilterSlot\0SetFilterVoxelGridXYZSlot\0"
    "SetFilterBoundingBoxSlot\0SetFilterMeanKSlot\0"
    "meanK\0SetFilterStddevMulThreshSlot\0"
    "stddevMulThresh\0ChangeCorrespondencesTabSlot\0"
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
    "outlierThreshold\0"
    "SetRegestrationTransformationEpsilonSlot\0"
    "transformationEpsilon\0"
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
    "ChangeSmoothingTabSlot\0ProcessSmoothingSlot\0"
    "SetSmoothingNumIterSlot\0numIter\0"
    "SetSmoothingConvergenceSlot\0convergence\0"
    "SetSmoothingRelaxationFactorMaxAngleSlot\0"
    "relaxationFactor\0SetSmoothingFeatureAngleSlot\0"
    "featureAngle\0SetSmoothingSearchRadiusSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      72,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  374,    3, 0x06 /* Public */,
       1,    3,  383,    3, 0x26 /* Public | MethodCloned */,
       1,    2,  390,    3, 0x26 /* Public | MethodCloned */,
       1,    1,  395,    3, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  398,    3, 0x0a /* Public */,
      13,    1,  401,    3, 0x0a /* Public */,
      16,    4,  404,    3, 0x0a /* Public */,
      16,    3,  413,    3, 0x2a /* Public | MethodCloned */,
      16,    2,  420,    3, 0x2a /* Public | MethodCloned */,
      16,    1,  425,    3, 0x2a /* Public | MethodCloned */,
      17,    0,  428,    3, 0x0a /* Public */,
      18,    0,  429,    3, 0x0a /* Public */,
      19,    0,  430,    3, 0x0a /* Public */,
      20,    0,  431,    3, 0x0a /* Public */,
      21,    0,  432,    3, 0x0a /* Public */,
      22,    0,  433,    3, 0x0a /* Public */,
      23,    0,  434,    3, 0x0a /* Public */,
      24,    0,  435,    3, 0x0a /* Public */,
      25,    0,  436,    3, 0x0a /* Public */,
      26,    0,  437,    3, 0x0a /* Public */,
      27,    0,  438,    3, 0x0a /* Public */,
      28,    0,  439,    3, 0x0a /* Public */,
      29,    1,  440,    3, 0x0a /* Public */,
      30,    0,  443,    3, 0x0a /* Public */,
      31,    0,  444,    3, 0x0a /* Public */,
      32,    0,  445,    3, 0x0a /* Public */,
      33,    0,  446,    3, 0x0a /* Public */,
      34,    0,  447,    3, 0x0a /* Public */,
      35,    0,  448,    3, 0x0a /* Public */,
      36,    1,  449,    3, 0x0a /* Public */,
      38,    0,  452,    3, 0x0a /* Public */,
      39,    0,  453,    3, 0x0a /* Public */,
      40,    0,  454,    3, 0x0a /* Public */,
      41,    0,  455,    3, 0x0a /* Public */,
      42,    1,  456,    3, 0x0a /* Public */,
      43,    1,  459,    3, 0x0a /* Public */,
      44,    0,  462,    3, 0x0a /* Public */,
      45,    0,  463,    3, 0x0a /* Public */,
      46,    0,  464,    3, 0x0a /* Public */,
      47,    1,  465,    3, 0x0a /* Public */,
      49,    1,  468,    3, 0x0a /* Public */,
      51,    1,  471,    3, 0x0a /* Public */,
      52,    0,  474,    3, 0x0a /* Public */,
      53,    1,  475,    3, 0x0a /* Public */,
      55,    1,  478,    3, 0x0a /* Public */,
      57,    1,  481,    3, 0x0a /* Public */,
      59,    1,  484,    3, 0x0a /* Public */,
      61,    1,  487,    3, 0x0a /* Public */,
      63,    0,  490,    3, 0x0a /* Public */,
      64,    1,  491,    3, 0x0a /* Public */,
      66,    1,  494,    3, 0x0a /* Public */,
      68,    1,  497,    3, 0x0a /* Public */,
      70,    1,  500,    3, 0x0a /* Public */,
      72,    1,  503,    3, 0x0a /* Public */,
      73,    0,  506,    3, 0x0a /* Public */,
      74,    1,  507,    3, 0x0a /* Public */,
      76,    1,  510,    3, 0x0a /* Public */,
      78,    1,  513,    3, 0x0a /* Public */,
      80,    1,  516,    3, 0x0a /* Public */,
      82,    1,  519,    3, 0x0a /* Public */,
      84,    1,  522,    3, 0x0a /* Public */,
      86,    0,  525,    3, 0x0a /* Public */,
      87,    1,  526,    3, 0x0a /* Public */,
      89,    1,  529,    3, 0x0a /* Public */,
      91,    1,  532,    3, 0x0a /* Public */,
      92,    1,  535,    3, 0x0a /* Public */,
      93,    0,  538,    3, 0x0a /* Public */,
      94,    1,  539,    3, 0x0a /* Public */,
      96,    1,  542,    3, 0x0a /* Public */,
      98,    1,  545,    3, 0x0a /* Public */,
     100,    1,  548,    3, 0x0a /* Public */,
     102,    1,  551,    3, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   48,
    QMetaType::Void, QMetaType::Double,   50,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   54,
    QMetaType::Void, QMetaType::Int,   56,
    QMetaType::Void, QMetaType::Double,   58,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void, QMetaType::Double,   62,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   65,
    QMetaType::Void, QMetaType::Double,   67,
    QMetaType::Void, QMetaType::Double,   69,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   75,
    QMetaType::Void, QMetaType::Double,   77,
    QMetaType::Void, QMetaType::Int,   79,
    QMetaType::Void, QMetaType::Int,   81,
    QMetaType::Void, QMetaType::Int,   83,
    QMetaType::Void, QMetaType::Int,   85,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   88,
    QMetaType::Void, QMetaType::Double,   90,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   95,
    QMetaType::Void, QMetaType::Double,   97,
    QMetaType::Void, QMetaType::Double,   99,
    QMetaType::Void, QMetaType::Int,  101,
    QMetaType::Void, QMetaType::Double,   75,

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
        case 10: _t->OpenFileSlot(); break;
        case 11: _t->SaveFileSlot(); break;
        case 12: _t->StartFlexxCameraSlot(); break;
        case 13: _t->StartRSCameraSlot(); break;
        case 14: _t->StopCameraSlot(); break;
        case 15: _t->SetCameraDepthConfidenceSlot(); break;
        case 16: _t->GetNumberOfBytesSlot(); break;
        case 17: _t->GetCharSlot(); break;
        case 18: _t->GetArraySlot(); break;
        case 19: _t->ControlMotorSlot(); break;
        case 20: _t->KeepOneFrameSlot(); break;
        case 21: _t->KeepContinueFrameSlot(); break;
        case 22: _t->KeepFrameArrivedSlot((*reinterpret_cast< pcl::PointCloud<PointT>::Ptr(*)>(_a[1]))); break;
        case 23: _t->RemoveSelectedPointCloudSlot(); break;
        case 24: _t->RemoveAllPointCloudSlot(); break;
        case 25: _t->SelectAllPointCloudSlot(); break;
        case 26: _t->UnselectAllPointCloudSlot(); break;
        case 27: _t->ProcessKeypoint2ICPSlot(); break;
        case 28: _t->ProcessKeypointSlot(); break;
        case 29: _t->ChangeKeypointTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->SetKeypointScalesSlot(); break;
        case 31: _t->SetKeypointMinContrastSlot(); break;
        case 32: _t->SetKeypointRadiusSlot(); break;
        case 33: _t->SetKeypointRadiusSearchSlot(); break;
        case 34: _t->SetKeypointMethodSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->ChangeFilterTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->ProcessFilterSlot(); break;
        case 37: _t->SetFilterVoxelGridXYZSlot(); break;
        case 38: _t->SetFilterBoundingBoxSlot(); break;
        case 39: _t->SetFilterMeanKSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->SetFilterStddevMulThreshSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 41: _t->ChangeCorrespondencesTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->ProcessCorrespondencesSlot(); break;
        case 43: _t->SetCorrespondenceDescriptorRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 44: _t->SetCorrespondenceDescriptorKSearchSpinBoxSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->SetCorrespondenceNormalRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 46: _t->SetCorrespondencesKSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->SetRejectorInlierThresholdSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 48: _t->ProcessRegestrationSlot(); break;
        case 49: _t->SetRegestrationCorrespondenceDistanceSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 50: _t->SetRegestrationOutlierThresholdSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 51: _t->SetRegestrationTransformationEpsilonSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 52: _t->SetRegestrationMaxIterationsSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->ChangeReconstructTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->ProcessReconstructSlot(); break;
        case 55: _t->SetReconstructSearchRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 56: _t->SetReconstructMuSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 57: _t->SetReconstructMaxNearestNeighborsSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 58: _t->SetReconstructMaxSurfaceAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->SetReconstructMinAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->SetReconstructMaxAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 61: _t->SetReconstructGridResolutionXYZSlot(); break;
        case 62: _t->SetReconstructIsoLevelSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 63: _t->SetReconstructNormalSearchRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 64: _t->SetReconstructDepthSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: _t->ChangeSmoothingTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: _t->ProcessSmoothingSlot(); break;
        case 67: _t->SetSmoothingNumIterSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 68: _t->SetSmoothingConvergenceSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 69: _t->SetSmoothingRelaxationFactorMaxAngleSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 70: _t->SetSmoothingFeatureAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: _t->SetSmoothingSearchRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
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
        case 22:
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
        if (_id < 72)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 72;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 72)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 72;
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
