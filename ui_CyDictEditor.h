/********************************************************************************
** Form generated from reading UI file 'CyDictEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYDICTEDITOR_H
#define UI_CYDICTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CyDictEditor
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditSourceFile;
    QToolButton *toolButtonFileSelect;
    QListView *listViewFiles;
    QLabel *label;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *plainTextEditContent;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonValidate;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonMerge;
    QPushButton *pushButtonSplit;
    QLineEdit *lineEditWord;
    QPlainTextEdit *plainTextEditDefinition;
    QLabel *label_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QListView *listViewWordFromMap;
    QLabel *label_4;
    QListView *listViewWordFromFile;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditTargetFile;
    QPushButton *pushButtonCreateDict;
    QPushButton *pushButton;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QDialog *CyDictEditor)
    {
        if (CyDictEditor->objectName().isEmpty())
            CyDictEditor->setObjectName(QStringLiteral("CyDictEditor"));
        CyDictEditor->resize(1187, 584);
        layoutWidget = new QWidget(CyDictEditor);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 21, 260, 551));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEditSourceFile = new QLineEdit(layoutWidget);
        lineEditSourceFile->setObjectName(QStringLiteral("lineEditSourceFile"));

        horizontalLayout->addWidget(lineEditSourceFile);

        toolButtonFileSelect = new QToolButton(layoutWidget);
        toolButtonFileSelect->setObjectName(QStringLiteral("toolButtonFileSelect"));

        horizontalLayout->addWidget(toolButtonFileSelect);


        verticalLayout->addLayout(horizontalLayout);

        listViewFiles = new QListView(layoutWidget);
        listViewFiles->setObjectName(QStringLiteral("listViewFiles"));

        verticalLayout->addWidget(listViewFiles);


        verticalLayout_4->addLayout(verticalLayout);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        layoutWidget1 = new QWidget(CyDictEditor);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(277, 21, 561, 551));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        plainTextEditContent = new QPlainTextEdit(layoutWidget1);
        plainTextEditContent->setObjectName(QStringLiteral("plainTextEditContent"));

        verticalLayout_3->addWidget(plainTextEditContent);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonValidate = new QPushButton(layoutWidget1);
        pushButtonValidate->setObjectName(QStringLiteral("pushButtonValidate"));

        horizontalLayout_3->addWidget(pushButtonValidate);

        pushButtonSave = new QPushButton(layoutWidget1);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        horizontalLayout_3->addWidget(pushButtonSave);

        pushButtonMerge = new QPushButton(layoutWidget1);
        pushButtonMerge->setObjectName(QStringLiteral("pushButtonMerge"));

        horizontalLayout_3->addWidget(pushButtonMerge);

        pushButtonSplit = new QPushButton(layoutWidget1);
        pushButtonSplit->setObjectName(QStringLiteral("pushButtonSplit"));

        horizontalLayout_3->addWidget(pushButtonSplit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        lineEditWord = new QLineEdit(layoutWidget1);
        lineEditWord->setObjectName(QStringLiteral("lineEditWord"));

        verticalLayout_3->addWidget(lineEditWord);

        plainTextEditDefinition = new QPlainTextEdit(layoutWidget1);
        plainTextEditDefinition->setObjectName(QStringLiteral("plainTextEditDefinition"));

        verticalLayout_3->addWidget(plainTextEditDefinition);


        verticalLayout_5->addLayout(verticalLayout_3);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_2);

        layoutWidget2 = new QWidget(CyDictEditor);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(850, 20, 327, 551));
        verticalLayout_6 = new QVBoxLayout(layoutWidget2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listViewWordFromMap = new QListView(layoutWidget2);
        listViewWordFromMap->setObjectName(QStringLiteral("listViewWordFromMap"));

        verticalLayout_2->addWidget(listViewWordFromMap);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4, 0, Qt::AlignHCenter);

        listViewWordFromFile = new QListView(layoutWidget2);
        listViewWordFromFile->setObjectName(QStringLiteral("listViewWordFromFile"));

        verticalLayout_2->addWidget(listViewWordFromFile);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEditTargetFile = new QLineEdit(layoutWidget2);
        lineEditTargetFile->setObjectName(QStringLiteral("lineEditTargetFile"));

        horizontalLayout_2->addWidget(lineEditTargetFile);

        pushButtonCreateDict = new QPushButton(layoutWidget2);
        pushButtonCreateDict->setObjectName(QStringLiteral("pushButtonCreateDict"));

        horizontalLayout_2->addWidget(pushButtonCreateDict);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_2);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_3);

        menuBar = new QMenuBar(CyDictEditor);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1139, 21));
        mainToolBar = new QToolBar(CyDictEditor);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setGeometry(QRect(0, 0, 4, 12));
        statusBar = new QStatusBar(CyDictEditor);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 18));

        retranslateUi(CyDictEditor);

        QMetaObject::connectSlotsByName(CyDictEditor);
    } // setupUi

    void retranslateUi(QDialog *CyDictEditor)
    {
        CyDictEditor->setWindowTitle(QApplication::translate("CyDictEditor", "CyDictEditor", Q_NULLPTR));
        toolButtonFileSelect->setText(QApplication::translate("CyDictEditor", "...", Q_NULLPTR));
        label->setText(QApplication::translate("CyDictEditor", "<Select Source Files>", Q_NULLPTR));
        pushButtonValidate->setText(QApplication::translate("CyDictEditor", "Validate", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("CyDictEditor", "Save", Q_NULLPTR));
        pushButtonMerge->setText(QApplication::translate("CyDictEditor", "Merge", Q_NULLPTR));
        pushButtonSplit->setText(QApplication::translate("CyDictEditor", "Split", Q_NULLPTR));
        label_2->setText(QApplication::translate("CyDictEditor", "<Split Word and Definition parts>", Q_NULLPTR));
        label_4->setText(QApplication::translate("CyDictEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">&lt;\342\226\262From Memory&gt;   &lt;From File\342\226\274&gt;</span></p></body></html>", Q_NULLPTR));
        pushButtonCreateDict->setText(QApplication::translate("CyDictEditor", "Create Dict", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CyDictEditor", "PushButton", Q_NULLPTR));
        label_3->setText(QApplication::translate("CyDictEditor", "<Create ifo, idx, dict files>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CyDictEditor: public Ui_CyDictEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYDICTEDITOR_H
