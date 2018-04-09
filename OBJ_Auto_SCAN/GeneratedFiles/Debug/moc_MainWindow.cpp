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
    QByteArrayData data[70];
    char stringdata0[1374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "UpdateViewerSlot"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 28), // "pcl::PointCloud<PointT>::Ptr"
QT_MOC_LITERAL(4, 58, 10), // "pointCloud"
QT_MOC_LITERAL(5, 69, 19), // "TableItemChangeSlot"
QT_MOC_LITERAL(6, 89, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(7, 107, 4), // "item"
QT_MOC_LITERAL(8, 112, 12), // "OpenFileSlot"
QT_MOC_LITERAL(9, 125, 12), // "SaveFileSlot"
QT_MOC_LITERAL(10, 138, 20), // "StartFlexxCameraSlot"
QT_MOC_LITERAL(11, 159, 17), // "StartRSCameraSlot"
QT_MOC_LITERAL(12, 177, 14), // "StopCameraSlot"
QT_MOC_LITERAL(13, 192, 28), // "SetCameraDepthConfidenceSlot"
QT_MOC_LITERAL(14, 221, 20), // "GetNumberOfBytesSlot"
QT_MOC_LITERAL(15, 242, 11), // "GetCharSlot"
QT_MOC_LITERAL(16, 254, 12), // "GetArraySlot"
QT_MOC_LITERAL(17, 267, 16), // "ControlMotorSlot"
QT_MOC_LITERAL(18, 284, 16), // "KeepOneFrameSlot"
QT_MOC_LITERAL(19, 301, 21), // "KeepContinueFrameSlot"
QT_MOC_LITERAL(20, 323, 13), // "KeepFrameSlot"
QT_MOC_LITERAL(21, 337, 19), // "ProcessKeypointSlot"
QT_MOC_LITERAL(22, 357, 21), // "ChangeKeypointTabSlot"
QT_MOC_LITERAL(23, 379, 5), // "index"
QT_MOC_LITERAL(24, 385, 17), // "SetSIFTScalesSlot"
QT_MOC_LITERAL(25, 403, 22), // "SetSIFTMinContrastSlot"
QT_MOC_LITERAL(26, 426, 19), // "SetHarrisRadiusSlot"
QT_MOC_LITERAL(27, 446, 25), // "SetHarrisRadiusSearchSlot"
QT_MOC_LITERAL(28, 472, 19), // "SetHarrisMethodSlot"
QT_MOC_LITERAL(29, 492, 19), // "ChangeFilterTabSlot"
QT_MOC_LITERAL(30, 512, 17), // "ProcessFilterSlot"
QT_MOC_LITERAL(31, 530, 19), // "SetVoxelGridXYZSlot"
QT_MOC_LITERAL(32, 550, 18), // "SetBoundingBoxSlot"
QT_MOC_LITERAL(33, 569, 28), // "ChangeCorrespondencesTabSlot"
QT_MOC_LITERAL(34, 598, 26), // "ProcessCorrespondencesSlot"
QT_MOC_LITERAL(35, 625, 37), // "SetCorrespondenceDescriptorRa..."
QT_MOC_LITERAL(36, 663, 16), // "descriptorRadius"
QT_MOC_LITERAL(37, 680, 45), // "SetCorrespondenceDescriptorKS..."
QT_MOC_LITERAL(38, 726, 7), // "kSearch"
QT_MOC_LITERAL(39, 734, 33), // "SetCorrespondenceNormalRadius..."
QT_MOC_LITERAL(40, 768, 12), // "normalRadius"
QT_MOC_LITERAL(41, 781, 23), // "SetCorrespondencesKSlot"
QT_MOC_LITERAL(42, 805, 16), // "correspondencesK"
QT_MOC_LITERAL(43, 822, 30), // "SetRejectorInlierThresholdSlot"
QT_MOC_LITERAL(44, 853, 23), // "rejectorInlierThreshold"
QT_MOC_LITERAL(45, 877, 23), // "ProcessRegestrationSlot"
QT_MOC_LITERAL(46, 901, 32), // "SetICPCorrespondenceDistanceSlot"
QT_MOC_LITERAL(47, 934, 22), // "correspondenceDistance"
QT_MOC_LITERAL(48, 957, 26), // "SetICPOutlierThresholdSlot"
QT_MOC_LITERAL(49, 984, 16), // "outlierThreshold"
QT_MOC_LITERAL(50, 1001, 31), // "SetICPTransformationEpsilonSlot"
QT_MOC_LITERAL(51, 1033, 21), // "transformationEpsilon"
QT_MOC_LITERAL(52, 1055, 23), // "SetICPMaxIterationsSlot"
QT_MOC_LITERAL(53, 1079, 13), // "maxIterations"
QT_MOC_LITERAL(54, 1093, 22), // "ProcessReconstructSlot"
QT_MOC_LITERAL(55, 1116, 19), // "SetSearchRadiusSlot"
QT_MOC_LITERAL(56, 1136, 12), // "searchRadius"
QT_MOC_LITERAL(57, 1149, 9), // "SetMuSlot"
QT_MOC_LITERAL(58, 1159, 2), // "mu"
QT_MOC_LITERAL(59, 1162, 26), // "SetMaxNearestNeighborsSlot"
QT_MOC_LITERAL(60, 1189, 19), // "maxNearestNeighbors"
QT_MOC_LITERAL(61, 1209, 22), // "SetMaxSurfaceAngleSlot"
QT_MOC_LITERAL(62, 1232, 15), // "maxSurfaceAngle"
QT_MOC_LITERAL(63, 1248, 15), // "SetMinAngleSlot"
QT_MOC_LITERAL(64, 1264, 8), // "minAngle"
QT_MOC_LITERAL(65, 1273, 15), // "SetMaxAngleSlot"
QT_MOC_LITERAL(66, 1289, 8), // "maxAngle"
QT_MOC_LITERAL(67, 1298, 37), // "SetMarchingCubesGridResolutio..."
QT_MOC_LITERAL(68, 1336, 28), // "SetMarchingCubesIsoLevelSlot"
QT_MOC_LITERAL(69, 1365, 8) // "isoLevel"

    },
    "MainWindow\0UpdateViewerSlot\0\0"
    "pcl::PointCloud<PointT>::Ptr\0pointCloud\0"
    "TableItemChangeSlot\0QTableWidgetItem*\0"
    "item\0OpenFileSlot\0SaveFileSlot\0"
    "StartFlexxCameraSlot\0StartRSCameraSlot\0"
    "StopCameraSlot\0SetCameraDepthConfidenceSlot\0"
    "GetNumberOfBytesSlot\0GetCharSlot\0"
    "GetArraySlot\0ControlMotorSlot\0"
    "KeepOneFrameSlot\0KeepContinueFrameSlot\0"
    "KeepFrameSlot\0ProcessKeypointSlot\0"
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
    "maxIterations\0ProcessReconstructSlot\0"
    "SetSearchRadiusSlot\0searchRadius\0"
    "SetMuSlot\0mu\0SetMaxNearestNeighborsSlot\0"
    "maxNearestNeighbors\0SetMaxSurfaceAngleSlot\0"
    "maxSurfaceAngle\0SetMinAngleSlot\0"
    "minAngle\0SetMaxAngleSlot\0maxAngle\0"
    "SetMarchingCubesGridResolutionXYZSlot\0"
    "SetMarchingCubesIsoLevelSlot\0isoLevel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  249,    2, 0x0a /* Public */,
       5,    1,  252,    2, 0x0a /* Public */,
       8,    0,  255,    2, 0x0a /* Public */,
       9,    0,  256,    2, 0x0a /* Public */,
      10,    0,  257,    2, 0x0a /* Public */,
      11,    0,  258,    2, 0x0a /* Public */,
      12,    0,  259,    2, 0x0a /* Public */,
      13,    0,  260,    2, 0x0a /* Public */,
      14,    0,  261,    2, 0x0a /* Public */,
      15,    0,  262,    2, 0x0a /* Public */,
      16,    0,  263,    2, 0x0a /* Public */,
      17,    0,  264,    2, 0x0a /* Public */,
      18,    0,  265,    2, 0x0a /* Public */,
      19,    0,  266,    2, 0x0a /* Public */,
      20,    1,  267,    2, 0x0a /* Public */,
      21,    0,  270,    2, 0x0a /* Public */,
      22,    1,  271,    2, 0x0a /* Public */,
      24,    0,  274,    2, 0x0a /* Public */,
      25,    0,  275,    2, 0x0a /* Public */,
      26,    0,  276,    2, 0x0a /* Public */,
      27,    0,  277,    2, 0x0a /* Public */,
      28,    1,  278,    2, 0x0a /* Public */,
      29,    1,  281,    2, 0x0a /* Public */,
      30,    0,  284,    2, 0x0a /* Public */,
      31,    0,  285,    2, 0x0a /* Public */,
      32,    0,  286,    2, 0x0a /* Public */,
      33,    1,  287,    2, 0x0a /* Public */,
      34,    0,  290,    2, 0x0a /* Public */,
      35,    1,  291,    2, 0x0a /* Public */,
      37,    1,  294,    2, 0x0a /* Public */,
      39,    1,  297,    2, 0x0a /* Public */,
      41,    1,  300,    2, 0x0a /* Public */,
      43,    1,  303,    2, 0x0a /* Public */,
      45,    0,  306,    2, 0x0a /* Public */,
      46,    1,  307,    2, 0x0a /* Public */,
      48,    1,  310,    2, 0x0a /* Public */,
      50,    1,  313,    2, 0x0a /* Public */,
      52,    1,  316,    2, 0x0a /* Public */,
      54,    0,  319,    2, 0x0a /* Public */,
      55,    1,  320,    2, 0x0a /* Public */,
      57,    1,  323,    2, 0x0a /* Public */,
      59,    1,  326,    2, 0x0a /* Public */,
      61,    1,  329,    2, 0x0a /* Public */,
      63,    1,  332,    2, 0x0a /* Public */,
      65,    1,  335,    2, 0x0a /* Public */,
      67,    0,  338,    2, 0x0a /* Public */,
      68,    1,  339,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
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
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   36,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Double,   40,
    QMetaType::Void, QMetaType::Int,   42,
    QMetaType::Void, QMetaType::Double,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   47,
    QMetaType::Void, QMetaType::Double,   49,
    QMetaType::Void, QMetaType::Double,   51,
    QMetaType::Void, QMetaType::Int,   53,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   56,
    QMetaType::Void, QMetaType::Double,   58,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void, QMetaType::Int,   62,
    QMetaType::Void, QMetaType::Int,   64,
    QMetaType::Void, QMetaType::Int,   66,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   69,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdateViewerSlot((*reinterpret_cast< pcl::PointCloud<PointT>::Ptr(*)>(_a[1]))); break;
        case 1: _t->TableItemChangeSlot((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->OpenFileSlot(); break;
        case 3: _t->SaveFileSlot(); break;
        case 4: _t->StartFlexxCameraSlot(); break;
        case 5: _t->StartRSCameraSlot(); break;
        case 6: _t->StopCameraSlot(); break;
        case 7: _t->SetCameraDepthConfidenceSlot(); break;
        case 8: _t->GetNumberOfBytesSlot(); break;
        case 9: _t->GetCharSlot(); break;
        case 10: _t->GetArraySlot(); break;
        case 11: _t->ControlMotorSlot(); break;
        case 12: _t->KeepOneFrameSlot(); break;
        case 13: _t->KeepContinueFrameSlot(); break;
        case 14: _t->KeepFrameSlot((*reinterpret_cast< pcl::PointCloud<PointT>::Ptr(*)>(_a[1]))); break;
        case 15: _t->ProcessKeypointSlot(); break;
        case 16: _t->ChangeKeypointTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->SetSIFTScalesSlot(); break;
        case 18: _t->SetSIFTMinContrastSlot(); break;
        case 19: _t->SetHarrisRadiusSlot(); break;
        case 20: _t->SetHarrisRadiusSearchSlot(); break;
        case 21: _t->SetHarrisMethodSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->ChangeFilterTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->ProcessFilterSlot(); break;
        case 24: _t->SetVoxelGridXYZSlot(); break;
        case 25: _t->SetBoundingBoxSlot(); break;
        case 26: _t->ChangeCorrespondencesTabSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->ProcessCorrespondencesSlot(); break;
        case 28: _t->SetCorrespondenceDescriptorRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->SetCorrespondenceDescriptorKSearchSpinBoxSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->SetCorrespondenceNormalRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->SetCorrespondencesKSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->SetRejectorInlierThresholdSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 33: _t->ProcessRegestrationSlot(); break;
        case 34: _t->SetICPCorrespondenceDistanceSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 35: _t->SetICPOutlierThresholdSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: _t->SetICPTransformationEpsilonSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: _t->SetICPMaxIterationsSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->ProcessReconstructSlot(); break;
        case 39: _t->SetSearchRadiusSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 40: _t->SetMuSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 41: _t->SetMaxNearestNeighborsSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->SetMaxSurfaceAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->SetMinAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->SetMaxAngleSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->SetMarchingCubesGridResolutionXYZSlot(); break;
        case 46: _t->SetMarchingCubesIsoLevelSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pcl::PointCloud<PointT>::Ptr >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pcl::PointCloud<PointT>::Ptr >(); break;
            }
            break;
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
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
