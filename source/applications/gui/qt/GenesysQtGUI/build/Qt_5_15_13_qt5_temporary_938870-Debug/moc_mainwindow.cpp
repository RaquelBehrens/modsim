/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[108];
    char stringdata0[3355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_actionEditUndo_triggered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 27), // "on_actionEditRedo_triggered"
QT_MOC_LITERAL(4, 68, 27), // "on_actionEditFind_triggered"
QT_MOC_LITERAL(5, 96, 30), // "on_actionEditReplace_triggered"
QT_MOC_LITERAL(6, 127, 26), // "on_actionEditCut_triggered"
QT_MOC_LITERAL(7, 154, 27), // "on_actionEditCopy_triggered"
QT_MOC_LITERAL(8, 182, 28), // "on_actionEditPaste_triggered"
QT_MOC_LITERAL(9, 211, 29), // "on_actionEditDelete_triggered"
QT_MOC_LITERAL(10, 241, 28), // "on_actionEditGroup_triggered"
QT_MOC_LITERAL(11, 270, 30), // "on_actionEditUngroup_triggered"
QT_MOC_LITERAL(12, 301, 28), // "on_actionViewGroup_triggered"
QT_MOC_LITERAL(13, 330, 30), // "on_actionViewUngroup_triggered"
QT_MOC_LITERAL(14, 361, 27), // "on_actionShowGrid_triggered"
QT_MOC_LITERAL(15, 389, 27), // "on_actionShowRule_triggered"
QT_MOC_LITERAL(16, 417, 29), // "on_actionShowGuides_triggered"
QT_MOC_LITERAL(17, 447, 32), // "on_actionViewConfigure_triggered"
QT_MOC_LITERAL(18, 480, 26), // "on_actionZoom_In_triggered"
QT_MOC_LITERAL(19, 507, 27), // "on_actionZoom_Out_triggered"
QT_MOC_LITERAL(20, 535, 27), // "on_actionZoom_All_triggered"
QT_MOC_LITERAL(21, 563, 27), // "on_actionDrawLine_triggered"
QT_MOC_LITERAL(22, 591, 32), // "on_actionDrawRectangle_triggered"
QT_MOC_LITERAL(23, 624, 30), // "on_actionDrawEllipse_triggered"
QT_MOC_LITERAL(24, 655, 27), // "on_actionDrawText_triggered"
QT_MOC_LITERAL(25, 683, 30), // "on_actionDrawPoligon_triggered"
QT_MOC_LITERAL(26, 714, 39), // "on_actionAnimateSimulatedTime..."
QT_MOC_LITERAL(27, 754, 34), // "on_actionAnimateVariable_trig..."
QT_MOC_LITERAL(28, 789, 36), // "on_actionAnimateExpression_tr..."
QT_MOC_LITERAL(29, 826, 34), // "on_actionAnimateResource_trig..."
QT_MOC_LITERAL(30, 861, 31), // "on_actionAnimateQueue_triggered"
QT_MOC_LITERAL(31, 893, 33), // "on_actionAnimateStation_trigg..."
QT_MOC_LITERAL(32, 927, 33), // "on_actionAnimateCounter_trigg..."
QT_MOC_LITERAL(33, 961, 32), // "on_actionAnimateEntity_triggered"
QT_MOC_LITERAL(34, 994, 31), // "on_actionAnimateEvent_triggered"
QT_MOC_LITERAL(35, 1026, 35), // "on_actionAnimateAttribute_tri..."
QT_MOC_LITERAL(36, 1062, 36), // "on_actionAnimateStatistics_tr..."
QT_MOC_LITERAL(37, 1099, 30), // "on_actionAnimatePlot_triggered"
QT_MOC_LITERAL(38, 1130, 33), // "on_actionSimulationStop_trigg..."
QT_MOC_LITERAL(39, 1164, 34), // "on_actionSimulationStart_trig..."
QT_MOC_LITERAL(40, 1199, 33), // "on_actionSimulationStep_trigg..."
QT_MOC_LITERAL(41, 1233, 34), // "on_actionSimulationPause_trig..."
QT_MOC_LITERAL(42, 1268, 35), // "on_actionSimulationResume_tri..."
QT_MOC_LITERAL(43, 1304, 38), // "on_actionSimulationConfigure_..."
QT_MOC_LITERAL(44, 1343, 29), // "on_actionAboutAbout_triggered"
QT_MOC_LITERAL(45, 1373, 31), // "on_actionAboutLicence_triggered"
QT_MOC_LITERAL(46, 1405, 35), // "on_actionAboutGetInvolved_tri..."
QT_MOC_LITERAL(47, 1441, 30), // "on_actionAlignMiddle_triggered"
QT_MOC_LITERAL(48, 1472, 27), // "on_actionAlignTop_triggered"
QT_MOC_LITERAL(49, 1500, 29), // "on_actionAlignRight_triggered"
QT_MOC_LITERAL(50, 1530, 30), // "on_actionAlignCenter_triggered"
QT_MOC_LITERAL(51, 1561, 28), // "on_actionAlignLeft_triggered"
QT_MOC_LITERAL(52, 1590, 44), // "on_actionToolsParserGrammarCh..."
QT_MOC_LITERAL(53, 1635, 39), // "on_actionToolsExperimentation..."
QT_MOC_LITERAL(54, 1675, 35), // "on_actionToolsOptimizator_tri..."
QT_MOC_LITERAL(55, 1711, 36), // "on_actionToolsDataAnalyzer_tr..."
QT_MOC_LITERAL(56, 1748, 41), // "on_actionSimulatorPluginManag..."
QT_MOC_LITERAL(57, 1790, 32), // "on_actionSimulatorExit_triggered"
QT_MOC_LITERAL(58, 1823, 39), // "on_actionSimulatorPreferences..."
QT_MOC_LITERAL(59, 1863, 27), // "on_actionModelNew_triggered"
QT_MOC_LITERAL(60, 1891, 28), // "on_actionModelOpen_triggered"
QT_MOC_LITERAL(61, 1920, 28), // "on_actionModelSave_triggered"
QT_MOC_LITERAL(62, 1949, 29), // "on_actionModelClose_triggered"
QT_MOC_LITERAL(63, 1979, 35), // "on_actionModelInformation_tri..."
QT_MOC_LITERAL(64, 2015, 29), // "on_actionModelCheck_triggered"
QT_MOC_LITERAL(65, 2045, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(66, 2072, 39), // "on_actionComponent_Breakpoint..."
QT_MOC_LITERAL(67, 2112, 32), // "on_tabWidget_Model_tabBarClicked"
QT_MOC_LITERAL(68, 2145, 5), // "index"
QT_MOC_LITERAL(69, 2151, 33), // "on_tabWidget_Debug_currentCha..."
QT_MOC_LITERAL(70, 2185, 34), // "on_tabWidgetCentral_currentCh..."
QT_MOC_LITERAL(71, 2220, 33), // "on_tabWidgetCentral_tabBarCli..."
QT_MOC_LITERAL(72, 2254, 32), // "on_tabWidgetModel_currentChanged"
QT_MOC_LITERAL(73, 2287, 37), // "on_tabWidgetSimulation_curren..."
QT_MOC_LITERAL(74, 2325, 34), // "on_tabWidgetReports_currentCh..."
QT_MOC_LITERAL(75, 2360, 41), // "on_tabWidgetModelLanguages_cu..."
QT_MOC_LITERAL(76, 2402, 39), // "on_treeWidget_Plugins_itemDou..."
QT_MOC_LITERAL(77, 2442, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(78, 2459, 4), // "item"
QT_MOC_LITERAL(79, 2464, 6), // "column"
QT_MOC_LITERAL(80, 2471, 44), // "on_treeWidgetComponents_itemS..."
QT_MOC_LITERAL(81, 2516, 33), // "on_treeWidget_Plugins_itemCli..."
QT_MOC_LITERAL(82, 2550, 37), // "on_horizontalSlider_Zoom_valu..."
QT_MOC_LITERAL(83, 2588, 5), // "value"
QT_MOC_LITERAL(84, 2594, 46), // "on_horizontalSlider_ZoomGraph..."
QT_MOC_LITERAL(85, 2641, 37), // "on_checkBox_ShowElements_stat..."
QT_MOC_LITERAL(86, 2679, 4), // "arg1"
QT_MOC_LITERAL(87, 2684, 38), // "on_checkBox_ShowInternals_sta..."
QT_MOC_LITERAL(88, 2723, 38), // "on_checkBox_ShowRecursive_sta..."
QT_MOC_LITERAL(89, 2762, 35), // "on_checkBox_ShowLevels_stateC..."
QT_MOC_LITERAL(90, 2798, 39), // "on_pushButton_Breakpoint_Inse..."
QT_MOC_LITERAL(91, 2838, 39), // "on_pushButton_Breakpoint_Remo..."
QT_MOC_LITERAL(92, 2878, 28), // "on_pushButton_Export_clicked"
QT_MOC_LITERAL(93, 2907, 33), // "on_graphicsView_rubberBandCha..."
QT_MOC_LITERAL(94, 2941, 12), // "viewportRect"
QT_MOC_LITERAL(95, 2954, 14), // "fromScenePoint"
QT_MOC_LITERAL(96, 2969, 12), // "toScenePoint"
QT_MOC_LITERAL(97, 2982, 29), // "on_TextCodeEditor_textChanged"
QT_MOC_LITERAL(98, 3012, 45), // "on_treeWidgetDataDefnitions_i..."
QT_MOC_LITERAL(99, 3058, 39), // "on_treeWidgetDataDefnitions_i..."
QT_MOC_LITERAL(100, 3098, 30), // "on_actionArranjeLeft_triggered"
QT_MOC_LITERAL(101, 3129, 31), // "on_actionArranjeRight_triggered"
QT_MOC_LITERAL(102, 3161, 29), // "on_actionArranjeTop_triggered"
QT_MOC_LITERAL(103, 3191, 32), // "on_actionArranjeBototm_triggered"
QT_MOC_LITERAL(104, 3224, 32), // "on_actionArranjeCenter_triggered"
QT_MOC_LITERAL(105, 3257, 32), // "on_actionArranjeMiddle_triggered"
QT_MOC_LITERAL(106, 3290, 27), // "on_actionShowSnap_triggered"
QT_MOC_LITERAL(107, 3318, 36) // "on_actionGModelShowConnect_tr..."

    },
    "MainWindow\0on_actionEditUndo_triggered\0"
    "\0on_actionEditRedo_triggered\0"
    "on_actionEditFind_triggered\0"
    "on_actionEditReplace_triggered\0"
    "on_actionEditCut_triggered\0"
    "on_actionEditCopy_triggered\0"
    "on_actionEditPaste_triggered\0"
    "on_actionEditDelete_triggered\0"
    "on_actionEditGroup_triggered\0"
    "on_actionEditUngroup_triggered\0"
    "on_actionViewGroup_triggered\0"
    "on_actionViewUngroup_triggered\0"
    "on_actionShowGrid_triggered\0"
    "on_actionShowRule_triggered\0"
    "on_actionShowGuides_triggered\0"
    "on_actionViewConfigure_triggered\0"
    "on_actionZoom_In_triggered\0"
    "on_actionZoom_Out_triggered\0"
    "on_actionZoom_All_triggered\0"
    "on_actionDrawLine_triggered\0"
    "on_actionDrawRectangle_triggered\0"
    "on_actionDrawEllipse_triggered\0"
    "on_actionDrawText_triggered\0"
    "on_actionDrawPoligon_triggered\0"
    "on_actionAnimateSimulatedTime_triggered\0"
    "on_actionAnimateVariable_triggered\0"
    "on_actionAnimateExpression_triggered\0"
    "on_actionAnimateResource_triggered\0"
    "on_actionAnimateQueue_triggered\0"
    "on_actionAnimateStation_triggered\0"
    "on_actionAnimateCounter_triggered\0"
    "on_actionAnimateEntity_triggered\0"
    "on_actionAnimateEvent_triggered\0"
    "on_actionAnimateAttribute_triggered\0"
    "on_actionAnimateStatistics_triggered\0"
    "on_actionAnimatePlot_triggered\0"
    "on_actionSimulationStop_triggered\0"
    "on_actionSimulationStart_triggered\0"
    "on_actionSimulationStep_triggered\0"
    "on_actionSimulationPause_triggered\0"
    "on_actionSimulationResume_triggered\0"
    "on_actionSimulationConfigure_triggered\0"
    "on_actionAboutAbout_triggered\0"
    "on_actionAboutLicence_triggered\0"
    "on_actionAboutGetInvolved_triggered\0"
    "on_actionAlignMiddle_triggered\0"
    "on_actionAlignTop_triggered\0"
    "on_actionAlignRight_triggered\0"
    "on_actionAlignCenter_triggered\0"
    "on_actionAlignLeft_triggered\0"
    "on_actionToolsParserGrammarChecker_triggered\0"
    "on_actionToolsExperimentation_triggered\0"
    "on_actionToolsOptimizator_triggered\0"
    "on_actionToolsDataAnalyzer_triggered\0"
    "on_actionSimulatorPluginManager_triggered\0"
    "on_actionSimulatorExit_triggered\0"
    "on_actionSimulatorPreferences_triggered\0"
    "on_actionModelNew_triggered\0"
    "on_actionModelOpen_triggered\0"
    "on_actionModelSave_triggered\0"
    "on_actionModelClose_triggered\0"
    "on_actionModelInformation_triggered\0"
    "on_actionModelCheck_triggered\0"
    "on_actionConnect_triggered\0"
    "on_actionComponent_Breakpoint_triggered\0"
    "on_tabWidget_Model_tabBarClicked\0index\0"
    "on_tabWidget_Debug_currentChanged\0"
    "on_tabWidgetCentral_currentChanged\0"
    "on_tabWidgetCentral_tabBarClicked\0"
    "on_tabWidgetModel_currentChanged\0"
    "on_tabWidgetSimulation_currentChanged\0"
    "on_tabWidgetReports_currentChanged\0"
    "on_tabWidgetModelLanguages_currentChanged\0"
    "on_treeWidget_Plugins_itemDoubleClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_treeWidgetComponents_itemSelectionChanged\0"
    "on_treeWidget_Plugins_itemClicked\0"
    "on_horizontalSlider_Zoom_valueChanged\0"
    "value\0on_horizontalSlider_ZoomGraphical_valueChanged\0"
    "on_checkBox_ShowElements_stateChanged\0"
    "arg1\0on_checkBox_ShowInternals_stateChanged\0"
    "on_checkBox_ShowRecursive_stateChanged\0"
    "on_checkBox_ShowLevels_stateChanged\0"
    "on_pushButton_Breakpoint_Insert_clicked\0"
    "on_pushButton_Breakpoint_Remove_clicked\0"
    "on_pushButton_Export_clicked\0"
    "on_graphicsView_rubberBandChanged\0"
    "viewportRect\0fromScenePoint\0toScenePoint\0"
    "on_TextCodeEditor_textChanged\0"
    "on_treeWidgetDataDefnitions_itemDoubleClicked\0"
    "on_treeWidgetDataDefnitions_itemChanged\0"
    "on_actionArranjeLeft_triggered\0"
    "on_actionArranjeRight_triggered\0"
    "on_actionArranjeTop_triggered\0"
    "on_actionArranjeBototm_triggered\0"
    "on_actionArranjeCenter_triggered\0"
    "on_actionArranjeMiddle_triggered\0"
    "on_actionShowSnap_triggered\0"
    "on_actionGModelShowConnect_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      97,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  499,    2, 0x08 /* Private */,
       3,    0,  500,    2, 0x08 /* Private */,
       4,    0,  501,    2, 0x08 /* Private */,
       5,    0,  502,    2, 0x08 /* Private */,
       6,    0,  503,    2, 0x08 /* Private */,
       7,    0,  504,    2, 0x08 /* Private */,
       8,    0,  505,    2, 0x08 /* Private */,
       9,    0,  506,    2, 0x08 /* Private */,
      10,    0,  507,    2, 0x08 /* Private */,
      11,    0,  508,    2, 0x08 /* Private */,
      12,    0,  509,    2, 0x08 /* Private */,
      13,    0,  510,    2, 0x08 /* Private */,
      14,    0,  511,    2, 0x08 /* Private */,
      15,    0,  512,    2, 0x08 /* Private */,
      16,    0,  513,    2, 0x08 /* Private */,
      17,    0,  514,    2, 0x08 /* Private */,
      18,    0,  515,    2, 0x08 /* Private */,
      19,    0,  516,    2, 0x08 /* Private */,
      20,    0,  517,    2, 0x08 /* Private */,
      21,    0,  518,    2, 0x08 /* Private */,
      22,    0,  519,    2, 0x08 /* Private */,
      23,    0,  520,    2, 0x08 /* Private */,
      24,    0,  521,    2, 0x08 /* Private */,
      25,    0,  522,    2, 0x08 /* Private */,
      26,    0,  523,    2, 0x08 /* Private */,
      27,    0,  524,    2, 0x08 /* Private */,
      28,    0,  525,    2, 0x08 /* Private */,
      29,    0,  526,    2, 0x08 /* Private */,
      30,    0,  527,    2, 0x08 /* Private */,
      31,    0,  528,    2, 0x08 /* Private */,
      32,    0,  529,    2, 0x08 /* Private */,
      33,    0,  530,    2, 0x08 /* Private */,
      34,    0,  531,    2, 0x08 /* Private */,
      35,    0,  532,    2, 0x08 /* Private */,
      36,    0,  533,    2, 0x08 /* Private */,
      37,    0,  534,    2, 0x08 /* Private */,
      38,    0,  535,    2, 0x08 /* Private */,
      39,    0,  536,    2, 0x08 /* Private */,
      40,    0,  537,    2, 0x08 /* Private */,
      41,    0,  538,    2, 0x08 /* Private */,
      42,    0,  539,    2, 0x08 /* Private */,
      43,    0,  540,    2, 0x08 /* Private */,
      44,    0,  541,    2, 0x08 /* Private */,
      45,    0,  542,    2, 0x08 /* Private */,
      46,    0,  543,    2, 0x08 /* Private */,
      47,    0,  544,    2, 0x08 /* Private */,
      48,    0,  545,    2, 0x08 /* Private */,
      49,    0,  546,    2, 0x08 /* Private */,
      50,    0,  547,    2, 0x08 /* Private */,
      51,    0,  548,    2, 0x08 /* Private */,
      52,    0,  549,    2, 0x08 /* Private */,
      53,    0,  550,    2, 0x08 /* Private */,
      54,    0,  551,    2, 0x08 /* Private */,
      55,    0,  552,    2, 0x08 /* Private */,
      56,    0,  553,    2, 0x08 /* Private */,
      57,    0,  554,    2, 0x08 /* Private */,
      58,    0,  555,    2, 0x08 /* Private */,
      59,    0,  556,    2, 0x08 /* Private */,
      60,    0,  557,    2, 0x08 /* Private */,
      61,    0,  558,    2, 0x08 /* Private */,
      62,    0,  559,    2, 0x08 /* Private */,
      63,    0,  560,    2, 0x08 /* Private */,
      64,    0,  561,    2, 0x08 /* Private */,
      65,    0,  562,    2, 0x08 /* Private */,
      66,    0,  563,    2, 0x08 /* Private */,
      67,    1,  564,    2, 0x08 /* Private */,
      69,    1,  567,    2, 0x08 /* Private */,
      70,    1,  570,    2, 0x08 /* Private */,
      71,    1,  573,    2, 0x08 /* Private */,
      72,    1,  576,    2, 0x08 /* Private */,
      73,    1,  579,    2, 0x08 /* Private */,
      74,    1,  582,    2, 0x08 /* Private */,
      75,    1,  585,    2, 0x08 /* Private */,
      76,    2,  588,    2, 0x08 /* Private */,
      80,    0,  593,    2, 0x08 /* Private */,
      81,    2,  594,    2, 0x08 /* Private */,
      82,    1,  599,    2, 0x08 /* Private */,
      84,    1,  602,    2, 0x08 /* Private */,
      85,    1,  605,    2, 0x08 /* Private */,
      87,    1,  608,    2, 0x08 /* Private */,
      88,    1,  611,    2, 0x08 /* Private */,
      89,    1,  614,    2, 0x08 /* Private */,
      90,    0,  617,    2, 0x08 /* Private */,
      91,    0,  618,    2, 0x08 /* Private */,
      92,    0,  619,    2, 0x08 /* Private */,
      93,    3,  620,    2, 0x08 /* Private */,
      97,    0,  627,    2, 0x08 /* Private */,
      98,    2,  628,    2, 0x08 /* Private */,
      99,    2,  633,    2, 0x08 /* Private */,
     100,    0,  638,    2, 0x08 /* Private */,
     101,    0,  639,    2, 0x08 /* Private */,
     102,    0,  640,    2, 0x08 /* Private */,
     103,    0,  641,    2, 0x08 /* Private */,
     104,    0,  642,    2, 0x08 /* Private */,
     105,    0,  643,    2, 0x08 /* Private */,
     106,    0,  644,    2, 0x08 /* Private */,
     107,    0,  645,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, 0x80000000 | 77, QMetaType::Int,   78,   79,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 77, QMetaType::Int,   78,   79,
    QMetaType::Void, QMetaType::Int,   83,
    QMetaType::Void, QMetaType::Int,   83,
    QMetaType::Void, QMetaType::Int,   86,
    QMetaType::Void, QMetaType::Int,   86,
    QMetaType::Void, QMetaType::Int,   86,
    QMetaType::Void, QMetaType::Int,   86,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect, QMetaType::QPointF, QMetaType::QPointF,   94,   95,   96,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 77, QMetaType::Int,   78,   79,
    QMetaType::Void, 0x80000000 | 77, QMetaType::Int,   78,   79,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionEditUndo_triggered(); break;
        case 1: _t->on_actionEditRedo_triggered(); break;
        case 2: _t->on_actionEditFind_triggered(); break;
        case 3: _t->on_actionEditReplace_triggered(); break;
        case 4: _t->on_actionEditCut_triggered(); break;
        case 5: _t->on_actionEditCopy_triggered(); break;
        case 6: _t->on_actionEditPaste_triggered(); break;
        case 7: _t->on_actionEditDelete_triggered(); break;
        case 8: _t->on_actionEditGroup_triggered(); break;
        case 9: _t->on_actionEditUngroup_triggered(); break;
        case 10: _t->on_actionViewGroup_triggered(); break;
        case 11: _t->on_actionViewUngroup_triggered(); break;
        case 12: _t->on_actionShowGrid_triggered(); break;
        case 13: _t->on_actionShowRule_triggered(); break;
        case 14: _t->on_actionShowGuides_triggered(); break;
        case 15: _t->on_actionViewConfigure_triggered(); break;
        case 16: _t->on_actionZoom_In_triggered(); break;
        case 17: _t->on_actionZoom_Out_triggered(); break;
        case 18: _t->on_actionZoom_All_triggered(); break;
        case 19: _t->on_actionDrawLine_triggered(); break;
        case 20: _t->on_actionDrawRectangle_triggered(); break;
        case 21: _t->on_actionDrawEllipse_triggered(); break;
        case 22: _t->on_actionDrawText_triggered(); break;
        case 23: _t->on_actionDrawPoligon_triggered(); break;
        case 24: _t->on_actionAnimateSimulatedTime_triggered(); break;
        case 25: _t->on_actionAnimateVariable_triggered(); break;
        case 26: _t->on_actionAnimateExpression_triggered(); break;
        case 27: _t->on_actionAnimateResource_triggered(); break;
        case 28: _t->on_actionAnimateQueue_triggered(); break;
        case 29: _t->on_actionAnimateStation_triggered(); break;
        case 30: _t->on_actionAnimateCounter_triggered(); break;
        case 31: _t->on_actionAnimateEntity_triggered(); break;
        case 32: _t->on_actionAnimateEvent_triggered(); break;
        case 33: _t->on_actionAnimateAttribute_triggered(); break;
        case 34: _t->on_actionAnimateStatistics_triggered(); break;
        case 35: _t->on_actionAnimatePlot_triggered(); break;
        case 36: _t->on_actionSimulationStop_triggered(); break;
        case 37: _t->on_actionSimulationStart_triggered(); break;
        case 38: _t->on_actionSimulationStep_triggered(); break;
        case 39: _t->on_actionSimulationPause_triggered(); break;
        case 40: _t->on_actionSimulationResume_triggered(); break;
        case 41: _t->on_actionSimulationConfigure_triggered(); break;
        case 42: _t->on_actionAboutAbout_triggered(); break;
        case 43: _t->on_actionAboutLicence_triggered(); break;
        case 44: _t->on_actionAboutGetInvolved_triggered(); break;
        case 45: _t->on_actionAlignMiddle_triggered(); break;
        case 46: _t->on_actionAlignTop_triggered(); break;
        case 47: _t->on_actionAlignRight_triggered(); break;
        case 48: _t->on_actionAlignCenter_triggered(); break;
        case 49: _t->on_actionAlignLeft_triggered(); break;
        case 50: _t->on_actionToolsParserGrammarChecker_triggered(); break;
        case 51: _t->on_actionToolsExperimentation_triggered(); break;
        case 52: _t->on_actionToolsOptimizator_triggered(); break;
        case 53: _t->on_actionToolsDataAnalyzer_triggered(); break;
        case 54: _t->on_actionSimulatorPluginManager_triggered(); break;
        case 55: _t->on_actionSimulatorExit_triggered(); break;
        case 56: _t->on_actionSimulatorPreferences_triggered(); break;
        case 57: _t->on_actionModelNew_triggered(); break;
        case 58: _t->on_actionModelOpen_triggered(); break;
        case 59: _t->on_actionModelSave_triggered(); break;
        case 60: _t->on_actionModelClose_triggered(); break;
        case 61: _t->on_actionModelInformation_triggered(); break;
        case 62: _t->on_actionModelCheck_triggered(); break;
        case 63: _t->on_actionConnect_triggered(); break;
        case 64: _t->on_actionComponent_Breakpoint_triggered(); break;
        case 65: _t->on_tabWidget_Model_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 66: _t->on_tabWidget_Debug_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 67: _t->on_tabWidgetCentral_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 68: _t->on_tabWidgetCentral_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 69: _t->on_tabWidgetModel_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 70: _t->on_tabWidgetSimulation_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: _t->on_tabWidgetReports_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 72: _t->on_tabWidgetModelLanguages_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 73: _t->on_treeWidget_Plugins_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 74: _t->on_treeWidgetComponents_itemSelectionChanged(); break;
        case 75: _t->on_treeWidget_Plugins_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 76: _t->on_horizontalSlider_Zoom_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 77: _t->on_horizontalSlider_ZoomGraphical_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 78: _t->on_checkBox_ShowElements_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 79: _t->on_checkBox_ShowInternals_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 80: _t->on_checkBox_ShowRecursive_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 81: _t->on_checkBox_ShowLevels_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 82: _t->on_pushButton_Breakpoint_Insert_clicked(); break;
        case 83: _t->on_pushButton_Breakpoint_Remove_clicked(); break;
        case 84: _t->on_pushButton_Export_clicked(); break;
        case 85: _t->on_graphicsView_rubberBandChanged((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2])),(*reinterpret_cast< const QPointF(*)>(_a[3]))); break;
        case 86: _t->on_TextCodeEditor_textChanged(); break;
        case 87: _t->on_treeWidgetDataDefnitions_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 88: _t->on_treeWidgetDataDefnitions_itemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 89: _t->on_actionArranjeLeft_triggered(); break;
        case 90: _t->on_actionArranjeRight_triggered(); break;
        case 91: _t->on_actionArranjeTop_triggered(); break;
        case 92: _t->on_actionArranjeBototm_triggered(); break;
        case 93: _t->on_actionArranjeCenter_triggered(); break;
        case 94: _t->on_actionArranjeMiddle_triggered(); break;
        case 95: _t->on_actionShowSnap_triggered(); break;
        case 96: _t->on_actionGModelShowConnect_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 97)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 97;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 97)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 97;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
