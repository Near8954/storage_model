//
// Created by near on 06.10.24.
//

#include "App.h"

#include <iostream>
#include <qcoreapplication.h>

App::App() {
    setFixedSize(resolution_.first, resolution_.second);
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(QPixmap("../front/res/background.jpg")));
    setPalette(palette);
    palette.setBrush(QPalette::Button, QBrush(QPixmap("../front/res/mail.png")));
    mainScreen_ = new QLabel(this);
    mainScreen_->resize(resolution_.first, resolution_.second);
    mailButton_ = new QPushButton(mainScreen_);
    mailButton_->resize(100, 100);
    mailButton_->move(30, 130);
    mailButton_->setIcon(QIcon("../front/res/mail.png"));
    mailButton_->setIconSize(QSize(100, 100));
    mailButton_->setStyleSheet("QPushButton { border: none; background: transparent; }");
    mailButton_->setEnabled(true);

    int fontId = QFontDatabase::addApplicationFont("../front/res/BigBlueTermPlusNerdFontMono-Regular.ttf");
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(fontFamily);
    font.setPointSize(14);
    QFontMetrics metrics(font);
    mailLabel_ = new QLabel(mainScreen_);
    mailLabel_->setText("Mail");
    mailLabel_->setFont(font);
    mailLabel_->move(30 + 50 - metrics.horizontalAdvance(mailLabel_->text()) / 2, 130 + 100 + 10);
    mailLabel_->setStyleSheet("QLabel { color: white; }");

    storageButton_ = new QPushButton(mainScreen_);
    storageButton_->resize(100, 100);
    storageButton_->move(180, 130);
    storageButton_->setIcon(QIcon("../front/res/storage.png"));
    storageButton_->setIconSize(QSize(100, 100));
    storageButton_->setStyleSheet("QPushButton { border: none; background: transparent; }");
    storageButton_->setEnabled(true);

    connect(mailButton_, &QPushButton::clicked, this, &App::mail_clicked);
    connect(storageButton_, &QPushButton::clicked, this, &App::storage_clicked);

    storageLabel_ = new QLabel(mainScreen_);
    storageLabel_->setText("Storage");
    storageLabel_->setFont(font);
    storageLabel_->move(180 + 50 - metrics.horizontalAdvance(storageLabel_->text()) / 2, 130 + 100 + 10);
    storageLabel_->setStyleSheet("QLabel { color: white; }");

    mailScreen_ = new QLabel(this);
    mailScreen_->resize(resolution_.first, resolution_.second);
    mailScreen_->hide();

    storageScreen_ = new QLabel(this);
    storageScreen_->resize(resolution_.first, resolution_.second);
    storageScreen_->hide();

    scrollArea_ = new QScrollArea(storageScreen_);
    scrollArea_->setStyleSheet("color: rgba(140, 140, 140, 0);");
    scrollArea_->setGeometry(0, 100, 430, resolution_.second - 170);
    scrollAreaWidget_ = new QWidget();
    scrollArea_->setWidget(scrollAreaWidget_);
    scrollArea_->setWidgetResizable(true);
    scrollArea_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    scrollAreaLayout_ = new QVBoxLayout(scrollAreaWidget_);
    for (int i = 0; i < 50; ++i) {
        auto *card = new ProductCard(0, 0, scrollAreaWidget_);
        card->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        card->setMinimumSize(400, 150);
        scrollAreaLayout_->addWidget(card);
        product_cards_.push_back(card);
    }
}

App::~App() {
    for (auto &e: product_cards_) {
        delete e;
        e = nullptr;
    }
}

void App::mail_clicked() {
    if (mail_btn_clicked_cnt_ == 0) {
        ++mail_btn_clicked_cnt_;
        mailButton_->setStyleSheet("QPushButton { border: 2px solid blue; background: rgba(0, 0, 255, 50); }");
    } else if (mail_btn_clicked_cnt_ == 1) {
        mailButton_->setStyleSheet("QPushButton { border: none; background: transparent; }");
        mail_btn_clicked_cnt_ = 0;
        mainScreen_->hide();
        mailScreen_->show();
    }
}

void App::storage_clicked() {
    if (storage_btn_clicked_cnt_ == 0) {
        ++storage_btn_clicked_cnt_;
        storageButton_->setStyleSheet("QPushButton { border: 2px solid blue; background: rgba(0, 0, 255, 50); }");
    } else if (storage_btn_clicked_cnt_ == 1) {
        storageButton_->setStyleSheet("QPushButton { border: none; background: transparent; }");
        storage_btn_clicked_cnt_ = 0;
        mainScreen_->hide();
        storageScreen_->show();
    }
}

void App::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question(
        this, "App",
        tr("Are you sure you want to close the application?\n"),
        QMessageBox::No | QMessageBox::Yes,
        QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}

void App::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Escape:
            storageScreen_->hide();
            mailScreen_->hide();
            mainScreen_->show();
            break;
    }
}
