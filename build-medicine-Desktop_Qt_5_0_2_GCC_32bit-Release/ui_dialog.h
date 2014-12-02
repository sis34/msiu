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
    QTextEdit *start_rest;
    QTextEdit *start_top;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *end_rest;
    QTextEdit *start_first_minute;
    QTextEdit *end_first_minute;
    QTextEdit *end_top;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *start_third_minute;
    QTextEdit *end_third_minute;
    QTextEdit *start_fifth_minute;
    QTextEdit *end_fifth_minute;
    QLabel *label_9;
    QLabel *label_10;
    QTextEdit *start_seventh_minute;
    QTextEdit *end_seventh_minute;
    QLabel *label_11;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(476, 722);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(330, 630, 101, 71));
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setAutoFillBackground(false);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        start_rest = new QTextEdit(Dialog);
        start_rest->setObjectName(QStringLiteral("start_rest"));
        start_rest->setGeometry(QRect(160, 160, 104, 64));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(start_rest->sizePolicy().hasHeightForWidth());
        start_rest->setSizePolicy(sizePolicy);
        start_rest->setFocusPolicy(Qt::WheelFocus);
        start_rest->setInputMethodHints(Qt::ImhDigitsOnly);
        start_rest->setAutoFormatting(QTextEdit::AutoAll);
        start_rest->setTabChangesFocus(true);
        start_top = new QTextEdit(Dialog);
        start_top->setObjectName(QStringLiteral("start_top"));
        start_top->setGeometry(QRect(160, 240, 104, 64));
        sizePolicy.setHeightForWidth(start_top->sizePolicy().hasHeightForWidth());
        start_top->setSizePolicy(sizePolicy);
        start_top->setFocusPolicy(Qt::WheelFocus);
        start_top->setInputMethodHints(Qt::ImhDigitsOnly);
        start_top->setTabChangesFocus(true);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 135, 81, 21));
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 129, 81, 31));
        label_2->setFont(font);
        end_rest = new QTextEdit(Dialog);
        end_rest->setObjectName(QStringLiteral("end_rest"));
        end_rest->setGeometry(QRect(280, 160, 104, 64));
        sizePolicy.setHeightForWidth(end_rest->sizePolicy().hasHeightForWidth());
        end_rest->setSizePolicy(sizePolicy);
        end_rest->setFocusPolicy(Qt::WheelFocus);
        end_rest->setInputMethodHints(Qt::ImhDigitsOnly);
        end_rest->setAutoFormatting(QTextEdit::AutoAll);
        end_rest->setTabChangesFocus(true);
        start_first_minute = new QTextEdit(Dialog);
        start_first_minute->setObjectName(QStringLiteral("start_first_minute"));
        start_first_minute->setGeometry(QRect(160, 320, 104, 64));
        sizePolicy.setHeightForWidth(start_first_minute->sizePolicy().hasHeightForWidth());
        start_first_minute->setSizePolicy(sizePolicy);
        start_first_minute->setInputMethodHints(Qt::ImhDigitsOnly);
        start_first_minute->setAutoFormatting(QTextEdit::AutoAll);
        start_first_minute->setTabChangesFocus(true);
        end_first_minute = new QTextEdit(Dialog);
        end_first_minute->setObjectName(QStringLiteral("end_first_minute"));
        end_first_minute->setGeometry(QRect(280, 320, 104, 64));
        sizePolicy.setHeightForWidth(end_first_minute->sizePolicy().hasHeightForWidth());
        end_first_minute->setSizePolicy(sizePolicy);
        end_first_minute->setInputMethodHints(Qt::ImhDigitsOnly);
        end_first_minute->setAutoFormatting(QTextEdit::AutoAll);
        end_first_minute->setTabChangesFocus(true);
        end_top = new QTextEdit(Dialog);
        end_top->setObjectName(QStringLiteral("end_top"));
        end_top->setGeometry(QRect(280, 240, 104, 64));
        sizePolicy.setHeightForWidth(end_top->sizePolicy().hasHeightForWidth());
        end_top->setSizePolicy(sizePolicy);
        end_top->setInputMethodHints(Qt::ImhDigitsOnly);
        end_top->setTabChangesFocus(true);
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 180, 91, 21));
        label_6->setFont(font);
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 260, 81, 31));
        label_7->setFont(font);
        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 330, 111, 31));
        label_8->setFont(font);
        start_third_minute = new QTextEdit(Dialog);
        start_third_minute->setObjectName(QStringLiteral("start_third_minute"));
        start_third_minute->setGeometry(QRect(160, 400, 104, 64));
        sizePolicy.setHeightForWidth(start_third_minute->sizePolicy().hasHeightForWidth());
        start_third_minute->setSizePolicy(sizePolicy);
        start_third_minute->setInputMethodHints(Qt::ImhDigitsOnly);
        start_third_minute->setAutoFormatting(QTextEdit::AutoAll);
        start_third_minute->setTabChangesFocus(true);
        end_third_minute = new QTextEdit(Dialog);
        end_third_minute->setObjectName(QStringLiteral("end_third_minute"));
        end_third_minute->setGeometry(QRect(280, 400, 104, 64));
        sizePolicy.setHeightForWidth(end_third_minute->sizePolicy().hasHeightForWidth());
        end_third_minute->setSizePolicy(sizePolicy);
        end_third_minute->setInputMethodHints(Qt::ImhDigitsOnly);
        end_third_minute->setAutoFormatting(QTextEdit::AutoAll);
        end_third_minute->setTabChangesFocus(true);
        start_fifth_minute = new QTextEdit(Dialog);
        start_fifth_minute->setObjectName(QStringLiteral("start_fifth_minute"));
        start_fifth_minute->setGeometry(QRect(160, 480, 104, 64));
        sizePolicy.setHeightForWidth(start_fifth_minute->sizePolicy().hasHeightForWidth());
        start_fifth_minute->setSizePolicy(sizePolicy);
        start_fifth_minute->setInputMethodHints(Qt::ImhDigitsOnly);
        start_fifth_minute->setAutoFormatting(QTextEdit::AutoAll);
        start_fifth_minute->setTabChangesFocus(true);
        end_fifth_minute = new QTextEdit(Dialog);
        end_fifth_minute->setObjectName(QStringLiteral("end_fifth_minute"));
        end_fifth_minute->setGeometry(QRect(280, 480, 104, 64));
        sizePolicy.setHeightForWidth(end_fifth_minute->sizePolicy().hasHeightForWidth());
        end_fifth_minute->setSizePolicy(sizePolicy);
        end_fifth_minute->setInputMethodHints(Qt::ImhDigitsOnly);
        end_fifth_minute->setAutoFormatting(QTextEdit::AutoAll);
        end_fifth_minute->setTabChangesFocus(true);
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 420, 111, 31));
        label_9->setFont(font);
        label_10 = new QLabel(Dialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(50, 500, 81, 16));
        label_10->setFont(font);
        start_seventh_minute = new QTextEdit(Dialog);
        start_seventh_minute->setObjectName(QStringLiteral("start_seventh_minute"));
        start_seventh_minute->setGeometry(QRect(160, 560, 104, 64));
        sizePolicy.setHeightForWidth(start_seventh_minute->sizePolicy().hasHeightForWidth());
        start_seventh_minute->setSizePolicy(sizePolicy);
        start_seventh_minute->setInputMethodHints(Qt::ImhDigitsOnly);
        start_seventh_minute->setAutoFormatting(QTextEdit::AutoAll);
        start_seventh_minute->setTabChangesFocus(true);
        end_seventh_minute = new QTextEdit(Dialog);
        end_seventh_minute->setObjectName(QStringLiteral("end_seventh_minute"));
        end_seventh_minute->setGeometry(QRect(280, 560, 104, 64));
        sizePolicy.setHeightForWidth(end_seventh_minute->sizePolicy().hasHeightForWidth());
        end_seventh_minute->setSizePolicy(sizePolicy);
        end_seventh_minute->setInputMethodHints(Qt::ImhDigitsOnly);
        end_seventh_minute->setAutoFormatting(QTextEdit::AutoAll);
        end_seventh_minute->setTabChangesFocus(true);
        label_11 = new QLabel(Dialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(50, 580, 81, 16));
        label_11->setFont(font);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 15, 471, 91));
        label_3->setFont(font);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Form", 0));
#ifndef QT_NO_WHATSTHIS
        start_rest->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        start_top->setWhatsThis(QApplication::translate("Dialog", "\320\262\320\265\321\201", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("Dialog", "\320\235\320\260\321\207\320\260\320\273\320\276", 0));
        label_2->setText(QApplication::translate("Dialog", "\320\232\320\276\320\275\320\265\321\206", 0));
#ifndef QT_NO_WHATSTHIS
        end_rest->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        start_first_minute->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        end_first_minute->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        end_top->setWhatsThis(QApplication::translate("Dialog", "\320\262\320\265\321\201", 0));
#endif // QT_NO_WHATSTHIS
        label_6->setText(QApplication::translate("Dialog", "\320\237\320\276\320\272\320\276\320\271", 0));
        label_7->setText(QApplication::translate("Dialog", "\320\237\320\270\320\272", 0));
        label_8->setText(QApplication::translate("Dialog", "1\320\274\320\270\320\275.", 0));
#ifndef QT_NO_WHATSTHIS
        start_third_minute->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        end_third_minute->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        start_fifth_minute->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        end_fifth_minute->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
        label_9->setText(QApplication::translate("Dialog", "3\320\274\320\270\320\275.", 0));
        label_10->setText(QApplication::translate("Dialog", "5\320\274\320\270\320\275.", 0));
#ifndef QT_NO_WHATSTHIS
        start_seventh_minute->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_WHATSTHIS
        end_seventh_minute->setWhatsThis(QApplication::translate("Dialog", "\321\200\320\276\321\201\321\202", 0));
#endif // QT_NO_WHATSTHIS
        label_11->setText(QApplication::translate("Dialog", "7\320\274\320\270\320\275.", 0));
        label_3->setText(QApplication::translate("Dialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\262 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\321\203\321\216\321\211\320\270\320\265 \321\204\320\276\321\200\320\274\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
