/********************************************************************************
** Form generated from reading UI file 'BoundingBoxTestDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOUNDINGBOXTESTDIALOG_H
#define UI_BOUNDINGBOXTESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <qvtkwidget.h>

QT_BEGIN_NAMESPACE

class Ui_BoundingBoxTestDialog
{
public:
    QPushButton *_acceptButton;
    QPushButton *_rejectButton;
    QVTKWidget *_qvtkWidget;
    QScrollBar *_minXScrollBar;
    QScrollBar *_maxXScrollBar;
    QScrollBar *_minYScrollBar;
    QScrollBar *_maxYScrollBar;
    QScrollBar *_minZScrollBar;
    QScrollBar *_maxZScrollBar;
    QLabel *_minXLabel;
    QLabel *_maxXLabel;
    QLabel *_minYLabel;
    QLabel *_maxYLabel;
    QLabel *_minZLabel;
    QLabel *_maxZLabel;
    QLabel *_minXDisplayLabel;
    QLabel *_maxXDisplayLabel;
    QLabel *_minYDisplayLabel;
    QLabel *_maxYDisplayLabel;
    QLabel *_minZDisplayLabel;
    QLabel *_maxZDisplayLabel;

    void setupUi(QDialog *BoundingBoxTestDialog)
    {
        if (BoundingBoxTestDialog->objectName().isEmpty())
            BoundingBoxTestDialog->setObjectName(QStringLiteral("BoundingBoxTestDialog"));
        BoundingBoxTestDialog->resize(620, 590);
        _acceptButton = new QPushButton(BoundingBoxTestDialog);
        _acceptButton->setObjectName(QStringLiteral("_acceptButton"));
        _acceptButton->setGeometry(QRect(460, 480, 75, 30));
        QFont font;
        font.setPointSize(16);
        _acceptButton->setFont(font);
        _rejectButton = new QPushButton(BoundingBoxTestDialog);
        _rejectButton->setObjectName(QStringLiteral("_rejectButton"));
        _rejectButton->setGeometry(QRect(460, 530, 75, 30));
        _rejectButton->setFont(font);
        _qvtkWidget = new QVTKWidget(BoundingBoxTestDialog);
        _qvtkWidget->setObjectName(QStringLiteral("_qvtkWidget"));
        _qvtkWidget->setGeometry(QRect(30, 30, 400, 530));
        _minXScrollBar = new QScrollBar(BoundingBoxTestDialog);
        _minXScrollBar->setObjectName(QStringLiteral("_minXScrollBar"));
        _minXScrollBar->setGeometry(QRect(450, 70, 160, 16));
        _minXScrollBar->setMinimum(-1000);
        _minXScrollBar->setMaximum(1000);
        _minXScrollBar->setSingleStep(1);
        _minXScrollBar->setValue(-1000);
        _minXScrollBar->setOrientation(Qt::Horizontal);
        _maxXScrollBar = new QScrollBar(BoundingBoxTestDialog);
        _maxXScrollBar->setObjectName(QStringLiteral("_maxXScrollBar"));
        _maxXScrollBar->setGeometry(QRect(450, 140, 160, 16));
        _maxXScrollBar->setMinimum(-1000);
        _maxXScrollBar->setMaximum(1000);
        _maxXScrollBar->setSingleStep(1);
        _maxXScrollBar->setValue(1000);
        _maxXScrollBar->setOrientation(Qt::Horizontal);
        _minYScrollBar = new QScrollBar(BoundingBoxTestDialog);
        _minYScrollBar->setObjectName(QStringLiteral("_minYScrollBar"));
        _minYScrollBar->setGeometry(QRect(450, 210, 160, 16));
        _minYScrollBar->setMinimum(-1000);
        _minYScrollBar->setMaximum(1000);
        _minYScrollBar->setSingleStep(1);
        _minYScrollBar->setValue(-1000);
        _minYScrollBar->setOrientation(Qt::Horizontal);
        _maxYScrollBar = new QScrollBar(BoundingBoxTestDialog);
        _maxYScrollBar->setObjectName(QStringLiteral("_maxYScrollBar"));
        _maxYScrollBar->setGeometry(QRect(450, 280, 160, 16));
        _maxYScrollBar->setMinimum(-1000);
        _maxYScrollBar->setMaximum(1000);
        _maxYScrollBar->setSingleStep(1);
        _maxYScrollBar->setValue(1000);
        _maxYScrollBar->setOrientation(Qt::Horizontal);
        _minZScrollBar = new QScrollBar(BoundingBoxTestDialog);
        _minZScrollBar->setObjectName(QStringLiteral("_minZScrollBar"));
        _minZScrollBar->setGeometry(QRect(450, 350, 160, 16));
        _minZScrollBar->setMinimum(-1000);
        _minZScrollBar->setMaximum(1000);
        _minZScrollBar->setSingleStep(1);
        _minZScrollBar->setValue(-1000);
        _minZScrollBar->setOrientation(Qt::Horizontal);
        _maxZScrollBar = new QScrollBar(BoundingBoxTestDialog);
        _maxZScrollBar->setObjectName(QStringLiteral("_maxZScrollBar"));
        _maxZScrollBar->setGeometry(QRect(450, 420, 160, 16));
        _maxZScrollBar->setMinimum(-1000);
        _maxZScrollBar->setMaximum(1000);
        _maxZScrollBar->setSingleStep(1);
        _maxZScrollBar->setValue(1000);
        _maxZScrollBar->setOrientation(Qt::Horizontal);
        _minXLabel = new QLabel(BoundingBoxTestDialog);
        _minXLabel->setObjectName(QStringLiteral("_minXLabel"));
        _minXLabel->setGeometry(QRect(450, 30, 80, 30));
        _minXLabel->setFont(font);
        _maxXLabel = new QLabel(BoundingBoxTestDialog);
        _maxXLabel->setObjectName(QStringLiteral("_maxXLabel"));
        _maxXLabel->setGeometry(QRect(450, 100, 80, 30));
        _maxXLabel->setFont(font);
        _minYLabel = new QLabel(BoundingBoxTestDialog);
        _minYLabel->setObjectName(QStringLiteral("_minYLabel"));
        _minYLabel->setGeometry(QRect(450, 170, 80, 30));
        _minYLabel->setFont(font);
        _maxYLabel = new QLabel(BoundingBoxTestDialog);
        _maxYLabel->setObjectName(QStringLiteral("_maxYLabel"));
        _maxYLabel->setGeometry(QRect(450, 240, 80, 30));
        _maxYLabel->setFont(font);
        _minZLabel = new QLabel(BoundingBoxTestDialog);
        _minZLabel->setObjectName(QStringLiteral("_minZLabel"));
        _minZLabel->setGeometry(QRect(450, 310, 80, 30));
        _minZLabel->setFont(font);
        _maxZLabel = new QLabel(BoundingBoxTestDialog);
        _maxZLabel->setObjectName(QStringLiteral("_maxZLabel"));
        _maxZLabel->setGeometry(QRect(450, 380, 80, 30));
        _maxZLabel->setFont(font);
        _minXDisplayLabel = new QLabel(BoundingBoxTestDialog);
        _minXDisplayLabel->setObjectName(QStringLiteral("_minXDisplayLabel"));
        _minXDisplayLabel->setGeometry(QRect(530, 30, 80, 30));
        _minXDisplayLabel->setFont(font);
        _maxXDisplayLabel = new QLabel(BoundingBoxTestDialog);
        _maxXDisplayLabel->setObjectName(QStringLiteral("_maxXDisplayLabel"));
        _maxXDisplayLabel->setGeometry(QRect(530, 100, 80, 30));
        _maxXDisplayLabel->setFont(font);
        _minYDisplayLabel = new QLabel(BoundingBoxTestDialog);
        _minYDisplayLabel->setObjectName(QStringLiteral("_minYDisplayLabel"));
        _minYDisplayLabel->setGeometry(QRect(530, 170, 80, 30));
        _minYDisplayLabel->setFont(font);
        _maxYDisplayLabel = new QLabel(BoundingBoxTestDialog);
        _maxYDisplayLabel->setObjectName(QStringLiteral("_maxYDisplayLabel"));
        _maxYDisplayLabel->setGeometry(QRect(530, 240, 80, 30));
        _maxYDisplayLabel->setFont(font);
        _minZDisplayLabel = new QLabel(BoundingBoxTestDialog);
        _minZDisplayLabel->setObjectName(QStringLiteral("_minZDisplayLabel"));
        _minZDisplayLabel->setGeometry(QRect(530, 310, 80, 30));
        _minZDisplayLabel->setFont(font);
        _maxZDisplayLabel = new QLabel(BoundingBoxTestDialog);
        _maxZDisplayLabel->setObjectName(QStringLiteral("_maxZDisplayLabel"));
        _maxZDisplayLabel->setGeometry(QRect(530, 380, 80, 30));
        _maxZDisplayLabel->setFont(font);

        retranslateUi(BoundingBoxTestDialog);

        QMetaObject::connectSlotsByName(BoundingBoxTestDialog);
    } // setupUi

    void retranslateUi(QDialog *BoundingBoxTestDialog)
    {
        BoundingBoxTestDialog->setWindowTitle(QApplication::translate("BoundingBoxTestDialog", "Dialog", Q_NULLPTR));
        _acceptButton->setText(QApplication::translate("BoundingBoxTestDialog", "OK", Q_NULLPTR));
        _rejectButton->setText(QApplication::translate("BoundingBoxTestDialog", "Cancel", Q_NULLPTR));
        _minXLabel->setText(QApplication::translate("BoundingBoxTestDialog", "Min X\357\274\232", Q_NULLPTR));
        _maxXLabel->setText(QApplication::translate("BoundingBoxTestDialog", "Max X\357\274\232", Q_NULLPTR));
        _minYLabel->setText(QApplication::translate("BoundingBoxTestDialog", "Min Y\357\274\232", Q_NULLPTR));
        _maxYLabel->setText(QApplication::translate("BoundingBoxTestDialog", "Max Y\357\274\232", Q_NULLPTR));
        _minZLabel->setText(QApplication::translate("BoundingBoxTestDialog", "Min Z\357\274\232", Q_NULLPTR));
        _maxZLabel->setText(QApplication::translate("BoundingBoxTestDialog", "Max Z\357\274\232", Q_NULLPTR));
        _minXDisplayLabel->setText(QString());
        _maxXDisplayLabel->setText(QString());
        _minYDisplayLabel->setText(QString());
        _maxYDisplayLabel->setText(QString());
        _minZDisplayLabel->setText(QString());
        _maxZDisplayLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BoundingBoxTestDialog: public Ui_BoundingBoxTestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOUNDINGBOXTESTDIALOG_H
