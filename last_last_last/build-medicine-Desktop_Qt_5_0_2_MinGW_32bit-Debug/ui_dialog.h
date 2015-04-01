/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *rest_begin;
    QTextEdit *rest_end;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *top_begin;
    QTextEdit *top_end;
    QTextEdit *first_minute_begin;
    QTextEdit *first_minute_end;
    QTextEdit *third_minute_begin;
    QTextEdit *third_minute_end;
    QTextEdit *seventh_minute_begin;
    QTextEdit *fifth_minute_end;
    QTextEdit *seventh_minute_end;
    QTextEdit *fifth_minute_begin;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_11;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(522, 581);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 540, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        rest_begin = new QTextEdit(Dialog);
        rest_begin->setObjectName(QStringLiteral("rest_begin"));
        rest_begin->setGeometry(QRect(130, 50, 104, 64));
        rest_begin->setInputMethodHints(Qt::ImhDigitsOnly);
        rest_begin->setAutoFormatting(QTextEdit::AutoAll);
        rest_end = new QTextEdit(Dialog);
        rest_end->setObjectName(QStringLiteral("rest_end"));
        rest_end->setGeometry(QRect(280, 50, 104, 64));
        rest_end->setInputMethodHints(Qt::ImhDigitsOnly);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 46, 13));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 10, 46, 13));
        top_begin = new QTextEdit(Dialog);
        top_begin->setObjectName(QStringLiteral("top_begin"));
        top_begin->setGeometry(QRect(130, 130, 104, 64));
        top_begin->setInputMethodHints(Qt::ImhDigitsOnly);
        top_begin->setAutoFormatting(QTextEdit::AutoAll);
        top_end = new QTextEdit(Dialog);
        top_end->setObjectName(QStringLiteral("top_end"));
        top_end->setGeometry(QRect(280, 130, 104, 64));
        top_end->setInputMethodHints(Qt::ImhDigitsOnly);
        top_end->setAutoFormatting(QTextEdit::AutoAll);
        first_minute_begin = new QTextEdit(Dialog);
        first_minute_begin->setObjectName(QStringLiteral("first_minute_begin"));
        first_minute_begin->setGeometry(QRect(130, 210, 104, 64));
        first_minute_begin->setInputMethodHints(Qt::ImhDigitsOnly);
        first_minute_begin->setAutoFormatting(QTextEdit::AutoAll);
        first_minute_end = new QTextEdit(Dialog);
        first_minute_end->setObjectName(QStringLiteral("first_minute_end"));
        first_minute_end->setGeometry(QRect(280, 210, 104, 64));
        first_minute_end->setInputMethodHints(Qt::ImhDigitsOnly);
        first_minute_end->setAutoFormatting(QTextEdit::AutoAll);
        third_minute_begin = new QTextEdit(Dialog);
        third_minute_begin->setObjectName(QStringLiteral("third_minute_begin"));
        third_minute_begin->setGeometry(QRect(130, 300, 104, 64));
        third_minute_begin->setInputMethodHints(Qt::ImhDigitsOnly);
        third_minute_begin->setAutoFormatting(QTextEdit::AutoAll);
        third_minute_end = new QTextEdit(Dialog);
        third_minute_end->setObjectName(QStringLiteral("third_minute_end"));
        third_minute_end->setGeometry(QRect(280, 300, 104, 64));
        third_minute_end->setInputMethodHints(Qt::ImhDigitsOnly);
        third_minute_end->setAutoFormatting(QTextEdit::AutoAll);
        seventh_minute_begin = new QTextEdit(Dialog);
        seventh_minute_begin->setObjectName(QStringLiteral("seventh_minute_begin"));
        seventh_minute_begin->setGeometry(QRect(130, 460, 104, 64));
        seventh_minute_begin->setInputMethodHints(Qt::ImhDigitsOnly);
        seventh_minute_begin->setAutoFormatting(QTextEdit::AutoAll);
        fifth_minute_end = new QTextEdit(Dialog);
        fifth_minute_end->setObjectName(QStringLiteral("fifth_minute_end"));
        fifth_minute_end->setGeometry(QRect(280, 380, 104, 64));
        fifth_minute_end->setInputMethodHints(Qt::ImhDigitsOnly);
        fifth_minute_end->setAutoFormatting(QTextEdit::AutoAll);
        seventh_minute_end = new QTextEdit(Dialog);
        seventh_minute_end->setObjectName(QStringLiteral("seventh_minute_end"));
        seventh_minute_end->setGeometry(QRect(280, 460, 104, 64));
        seventh_minute_end->setInputMethodHints(Qt::ImhDigitsOnly);
        seventh_minute_end->setAutoFormatting(QTextEdit::AutoAll);
        fifth_minute_begin = new QTextEdit(Dialog);
        fifth_minute_begin->setObjectName(QStringLiteral("fifth_minute_begin"));
        fifth_minute_begin->setGeometry(QRect(130, 380, 104, 64));
        fifth_minute_begin->setInputMethodHints(Qt::ImhDigitsOnly);
        fifth_minute_begin->setAutoFormatting(QTextEdit::AutoAll);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 480, 71, 20));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 10, 46, 13));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(60, 150, 46, 13));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 220, 71, 20));
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(45, 400, 71, 20));
        label_11 = new QLabel(Dialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 320, 71, 20));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
#ifndef QT_NO_WHATSTHIS
        rest_begin->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        rest_end->setWhatsThis(QApplication::translate("Dialog", "\320\262\320\265\321\201", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("Dialog", "\320\237\320\276\320\272\320\276\320\271", 0));
        label_2->setText(QApplication::translate("Dialog", "\320\232\320\276\320\275\320\265\321\206", 0));
#ifndef QT_NO_WHATSTHIS
        top_begin->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        top_end->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        first_minute_begin->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        first_minute_end->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        third_minute_begin->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        third_minute_end->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        seventh_minute_begin->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        fifth_minute_end->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        seventh_minute_end->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        fifth_minute_begin->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("Dialog", "7-\321\217 \320\274\320\270\320\275\321\203\321\202\320\260", 0));
        label_5->setText(QApplication::translate("Dialog", "\320\235\320\260\321\207\320\260\320\273\320\276", 0));
        label_6->setText(QApplication::translate("Dialog", "\320\237\320\270\320\272", 0));
        label_7->setText(QApplication::translate("Dialog", "1-\321\217 \320\274\320\270\320\275\321\203\321\202\320\260", 0));
        label_9->setText(QApplication::translate("Dialog", "5-\321\217 \320\274\320\270\320\275\321\203\321\202\320\260", 0));
        label_11->setText(QApplication::translate("Dialog", "3-\321\217 \320\274\320\270\320\275\321\203\321\202\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
