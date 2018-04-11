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
    QByteArrayData data[84];
    char stringdata0[1539];
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
QT_MOC_LITERAL(30, 425, 12), // "AutoScanSlot"
QT_MOC_LITERAL(31, 438, 19), // "AutoScanArrivedSlot"
QT_MOC_LITERAL(32, 458, 19), // "ProcessKeypointSlot"
QT_MOC_LITERAL(33, 478, 21), // "ChangeKeypointTabSlot"
QT_MOC_LITERAL(34, 500, 5), // "index"
QT_MOC_LITERAL(35, 506, 17), // "SetSIFTScalesSlot"
QT_MOC_LITERAL(36, 524, 22), // "SetSIFTMinContrastSlot"
QT_MOC_LITERAL(37, 547, 19), // "SetHarrisRadiusSlot"
QT_MOC_LITERAL(38, 567, 25), // "SetHarrisRadiusSearchSlot"
QT_MOC_LITERAL(39, 593, 19), // "SetHarrisMethodSlot"
QT_MOC_LITERAL(40, 613, 19), // "ChangeFilterTabSlot"
QT_MOC_LITERAL(41, 633, 17), // "ProcessFilterSlot"
QT_MOC_LITERAL(42, 651, 19), // "SetVoxelGridXYZSlot"
QT_MOC_LITERAL(43, 671, 18), // "SetBoundingBoxSlot"
QT_MOC_LITERAL(44, 690, 28), // "ChangeCorrespondencesTabSlot"
QT_MOC_LITERAL(45, 719, 26), // "ProcessCorrespondencesSlot"
QT_MOC_LITERAL(46, 746, 37), // "SetCorrespondenceDescriptorRa..."
QT_MOC_LITERAL(47, 784, 16), // "descriptorRadius"
QT_MOC_LITERAL(48, 801, 45), // "SetCorrespondenceDescriptorKS..."
QT_MOC_LITERAL(49, 847, 7), // "kSearch"
QT_MOC_LITERAL(50, 855, 33), // "SetCorrespondenceNormalRadius..."
QT_MOC_LITERAL(51, 889, 12), // "normalRadius"
QT_MOC_LITERAL(52, 902, 23), // "SetCorrespondencesKSlot"
QT_MOC_LITERAL(53, 926, 16), // "correspondencesK"
QT_MOC_LITERAL(54, 943, 30), // "SetRejectorInlierThresholdSlot"
QT_MOC_LITERAL(55, 974, 23), // "rejectorInlierThreshold"
QT_MOC_LITERAL(56, 998, 23), // "ProcessRegestrationSlot"
QT_MOC_LITERAL(57, 1022, 32), // "SetICPCorrespondenceDistanceSlot"
QT_MOC_LITERAL(58, 1055, 22), // "correspondenceDistance"
QT_MOC_LITERAL(59, 1078, 26), // "SetICPOutlierThresholdSlot"
QT_MOC_LITERAL(60, 1105, 16), // "outlierThreshold"
QT_MOC_LITERAL(61, 1122, 31), // "SetICPTransformationEpsilonSlot"
QT_MOC_LITERAL(62, 1154, 21), // "transformationEpsilon"
QT_MOC_LITERAL(63, 1176, 23), // "SetICPMaxIterationsSlot"
QT_MOC_LITERAL(64, 1200, 13), // "maxIterations"
QT_MOC_LITERAL(65, 1214, 24), // "ChangeReconstructTabSlot"
QT_MOC_LITERAL(66, 1239, 22), // "ProcessReconstructSlot"
QT_MOC_LITERAL(67, 1262, 19), // "SetSearchRadiusSlot"
QT_MOC_LITERAL(68, 1282, 12), // "searchRadius"
QT_MOC_LITERAL(69, 1295, 9), // "SetMuSlot"
QT_MOC_LITERAL(70, 1305, 2), // "mu"
QT_MOC_LITERAL(71, 1308, 26), // "SetMaxNearestNeighborsSlot"
QT_MOC_LITERAL(72, 1335, 19), // "maxNearestNeighbors"
QT_MOC_LITERAL(73, 1355, 22), // "SetMaxSurfaceAngleSlot"
QT_MOC_LITERAL(74, 1378, 15), // "maxSurfaceAngle"
QT_MOC_LITERAL(75, 1394, 15), // "SetMinAngleSlot"
QT_MOC_LITERAL(76, 1410, 8), // "minAngle"
QT_MOC_LITERAL(77, 1419, 15), // "SetMaxAngleSlot"
QT_MOC_LITERAL(78, 1435, 8), // "maxAngle"
QT_MOC_LITERAL(79, 1444, 24), // "SetGridResolutionXYZSlot"
QT_MOC_LITERAL(80, 1469, 15), // "SetIsoLevelSlot"
QT_MOC_LITERAL(81, 1485, 8), // "isoLevel"
QT_MOC_LITERAL(82, 1494, 25), // "SetNormalSearchRadiusSlot"
QT_MOC_LITERAL(83, 1520, 18) // "normalSearchRadius"

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
    "KeepFrameArrivedSlot\0AutoScanSlot\0"
    "AutoScanArrivedSlot\0ProcessKeypointSlot\0"
    "ChangeKeypointTabSlot\0index\0"
    "SetSIFTScalesSlot\0SetSIFTMinContrastSlot\0"
    "SetHarrisRadiusSlot\0SetHarrisRadiusSearchSlot\0"
    "SetHarrisMethodSlot\0ChangeFilterTabSlot\0"
    "ProcessFilterSlot\0SetVoxelGridXYZSlot\0"
    "SetBoundingBoxSlot\0ChangeCorrespondencesTabSlot\0"
    "ProcessCorrespondencesSlot\0"
    "SetCorrespondenceDescriptorRadiusSlot\0"
    "descriptorRadius\0"
    "SetCorrespondenceDescriptorKSearchSpinBoxSlot\0"
    "kSearch\0SetCorrespondenceNormalRadiusSlot\0"
    "normalRadius\0SetCorrespondencesKSlot\0"
    "correspondencesK\0SetRejectorInlierThresholdSlot\0"
    "rejectorInlierThreshold\0ProcessRegestrationSlot\0"
    "SetICPCorrespondenceDistanceSlot\0"
    "correspondenceDistance\0"
    "SetICPOutlierThresholdSlot\0outlierThreshold\0"
    "SetICPTransformationEpsilonSlot\0"
    "transformationEpsilon\0SetICPMaxIterationsSlot\0"
    "maxIterations\0ChangeReconstructTabSlot\0"
    "ProcessReconstructSlot\0SetSearchRadiusSlot\0"
    "searchRadius\0SetMuSlot\0mu\0"
    "SetMaxNearestNeighborsSlot\0"
    "maxNearestNeighbors\0SetMaxSurfaceAngleSlot\0"
    "maxSurfaceAngle\0SetMinAngleSlot\0"
    "minAngle\0SetMaxAngleSlot\0maxAngle\0"
    "SetGridResolutionXYZSlot\0SetIsoLevelSlot\0"
    "isoLevel\0SetNormalSearchRadiusSlot\0"
    "normalSearchRadius"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      59,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  309,    3, 0x06 /* Public */,
       1,    3,  318,    3, 0x26 /* Public | MethodCloned */,
       1,    2,  325,    3, 0x26 /* Public | MethodCloned */,
       1,    1,  330,    3, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  333,    3, 0x0a /* Public */,
      13,    1,  336,    3, 0x0a /* Public */,
      16,    4,  339,    3, 0x0a /* Public */,
      16,    3,  348,    3, 0x2a /* Public | MethodCloned */,
      16,    2,  355,    3, 0x2a /* Public | MethodCloned */,
      16,    1,  360,    3, 0x2a /* Public | MethodCloned */,
      17,    0,  363,    3, 0x0a /* Public */,
      18,    0,  364,    3, 0x0a /* Public */,
      19,    0,  365,    3, 0x0a /* Public */,
      20,    0,  366,    3, 0x0a /* Public */,
      21,    0,  367,    3, 0x0a /* Public */,
      22,    0,  368,    3, 0x0a /* Public */,
      23,    0,  369,    3, 0x0a /* Public */,
      24,    0,  370,    3, 0x0a /* Public */,
      25,    0,  371,    3, 0x0a /* Public */,
      26,    0,  372,    3, 0x0a /* Public */,
      27,    0,  373,    3, 0x0a /* Public */,
      28,    0,  374,    3, 0x0a /* Public */,
      29,    1,  375,    3, 0x0a /* Public */,
      30,    0,  378,    3, 0x0a /* Public */,
      31,    1,  379,    3, 0x0a /* Public */,
      32,    0,  382,    3, 0x0a /* Public */,
      33,    1,  383,    3, 0x0a /* Public */,
      35,    0,  386,    3, 0x0a /* Public */,
      36,    0,  387,    3, 0x0a /* Public */,
      37,    0,  388,    3, 0x0a /* Public */,
      38,    0,  389,    3, 0x0a /* Public */,
      39,    1,  390,    3, 0x0a /* Public */,
      40,    1,  393,    3, 0x0a /* Public */,
      41,    0,  396,    3, 0x0a /* Public */,
      42,    0,  397,    3, 0x0a /* Public */,
      43,    0,  398,    3, 0x0a /* Public */,
      44,    1,  399,    3, 0x0a /* Public */,
      45,    0,  402,    3, 0x0a /* Public */,
      46,    1,  403,    3, 0x0a /* Public */,
      48,    1,  406,    3, 0x0a /* Public */,
      50,    1,  409,    3, 0x0a /* Public */,
      52,    1,  412,    3, 0x0a /* Public */,
      54,    1,  415,    3, 0x0a /* Public */,
      56,    0,  418,    3, 0x0a /* Public */,
      57,    1,  419,    3, 0x0a /* Public */,
      59,    1,  422,    3, 0x0a /* Public */,
      61,    1,  425,    3, 0x0a /* Public */,
      63,    1,  428,    3, 0x0a /* Public */,
      65,    1,  431,    3, 0x0a /* Public */,
      66,    0,  434,    3, 0x0a /* Public */,
      67,    1,  435,    3, 0x0a /* Public */,
      69,    1,  438,    3, 0x0a /* Public */,
      71,    1,  441,    3, 0x0a /* Public */,
      73,    1,  444,    3, 0x0a /* Public */,
      75,    1,  447,    3, 0x0a /* Public */,
      77,    1,  450,    3, 0x0a /* Public */,
      79,    0,  453,    3, 0x0a /* Public */,
      80,    1,  454,    3, 0x0a /* Public */,
      82,    1,  457,    3, 0x0a /* Public */,

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
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   47,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Double,   51,
    QMetaType::Void, QMetaType::Int,   53,
    QMetaType::Void, QMetaType::Double,   55,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   58,
    QMetaType::Void, QMetaType::Double,   60,
    QMetaType::Void, QMetaType::Double,   62,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   68,
    QMetaType::Void, QMetaType::Double,   70,
    QMetaType::Void, QMetaType::Int,   72,
    QMetaType::Void, QMetaType::Int,   74,
    QMetaType::Void, QMetaType::Int,   76,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   81,
    QMetaType::Void, QMetaType::Double,   83,

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
        case 23: _t->AutoScanSlot(); break;
        case 24: _t->AutoScanArrivedSlot((*reinterpret_cast< pcl::PointCloud<PointT>::Ptr(*)>(_a[1]))); break;
        case 25: _t->ProcessKeypointSlot(); break;
        case 26: _t->ChangeKeypointTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->SetSIFTScalesSlot(); break;
        case 28: _t->SetSIFTMinContrastSlot(); break;
        case 29: _t->SetHarrisRadiusSlot(); break;
        case 30: _t->SetHarrisRadiusSearchSlot(); break;
        case 31: _t->SetHarrisMethodSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->ChangeFilterTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->ProcessFilterSlot(); break;
        case 34: _t->SetVoxelGridXYZSlot(); break;
        case 35: _t->SetBoundingBoxSlot(); break;
        case 36: _t->ChangeCorrespondencesTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->ProcessCorrespondencesSlot(); break;
        case 38: _t->SetCorrespondenceDescriptorRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 39: _t->SetCorrespondenceDescriptorKSearchSpinBoxSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->SetCorrespondenceNormalRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 41: _t->SetCorrespondencesKSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->SetRejectorInlierThresholdSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 43: _t->ProcessRegestrationSlot(); break;
        case 44: _t->SetICPCorrespondenceDistanceSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 45: _t->SetICPOutlierThresholdSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 46: _t->SetICPTransformationEpsilonSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 47: _t->SetICPMaxIterationsSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->ChangeReconstructTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->ProcessReconstructSlot(); break;
        case 50: _t->SetSearchRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 51: _t->SetMuSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 52: _t->SetMaxNearestNeighborsSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->SetMaxSurfaceAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->SetMinAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->SetMaxAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->SetGridResolutionXYZSlot(); break;
        case 57: _t->SetIsoLevelSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 58: _t->SetNormalSearchRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
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
        case 24:
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
        if (_id < 59)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 59;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 59)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 59;
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
