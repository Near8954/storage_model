//
// Created by near on 08.10.24.
//

#include "ProductCard.h"

#include <QPainter>
#include <iostream>
#include <QFontMetrics>
#include <utility>

ProductCard::ProductCard(QWidget* parent) : QLabel(parent) {
    move(0, 0);
    resize(400, 150);
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::gray);
    this->setPalette(palette);

    imageLabel_ = new QLabel(this);
    imageLabel_->resize(100, 100);
    imageLabel_->setPixmap(QPixmap(QString::fromStdString("../noImage.jpg")).scaled(imageLabel_->size()));
    imageLabel_->setScaledContents(true);

    QFont font("Arial", 12);

    QFontMetrics metrics(font);

    productLabel_ = new QLabel(this);
    productLabel_->setText(QString::fromStdString("No name"));
    productLabel_->setFont(font);
    productLabel_->setStyleSheet("color: black;");
    productLabel_->move(imageLabel_->size().width() / 2 - metrics.horizontalAdvance(productLabel_->text()) / 2,
                        125 - metrics.height());
    productLabel_->resize(100, 30);

    productCountLabel_ = new QLabel(this);
    productCountLabel_->setText(
        QString::fromStdString("Количество товара на складе: NULL"));
    productCountLabel_->setFont(font);
    productCountLabel_->setStyleSheet("color: black;");
    productCountLabel_->move(110, 10);

    productCostLabel_ = new QLabel(this);
    productCostLabel_->setText(QString::fromStdString("Стоимость товара: NULL"));
    productCostLabel_->setFont(font);
    productCostLabel_->setStyleSheet("color: black;");
    productCostLabel_->move(110, 10 + metrics.height() + 10);

    bestBeforeDateLabel_ = new QLabel(this);
    bestBeforeDateLabel_->setText(QString::fromStdString("Срок годности: NULL"));
    bestBeforeDateLabel_->setFont(font);
    bestBeforeDateLabel_->setStyleSheet("color: black;");
    bestBeforeDateLabel_->move(110, 10 + metrics.height() + 10 + 10 + metrics.height());
}

ProductCard::ProductCard(int x, int y, QWidget *parent, std::string path)
    : x_(x), y_(y), QLabel(parent), path_(std::move(path)) {
    move(x, y);
    resize(400, 150);
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::gray);
    this->setPalette(palette);

    imageLabel_ = new QLabel(this);
    imageLabel_->resize(100, 100);
    imageLabel_->setPixmap(QPixmap(QString::fromStdString(path_)).scaled(imageLabel_->size()));
    imageLabel_->setScaledContents(true);

    QFont font("Arial", 12);

    QFontMetrics metrics(font);

    productLabel_ = new QLabel(this);
    productLabel_->setText(QString::fromStdString(name_));
    productLabel_->setFont(font);
    productLabel_->setStyleSheet("color: black;");
    productLabel_->move(imageLabel_->size().width() / 2 - metrics.horizontalAdvance(productLabel_->text()) / 2,
                        125 - metrics.height());
    productLabel_->resize(100, 30);

    productCountLabel_ = new QLabel(this);
    productCountLabel_->setText(
        QString::fromStdString("Количество товара на складе: " + std::to_string(product_count_)));
    productCountLabel_->setFont(font);
    productCountLabel_->setStyleSheet("color: black;");
    productCountLabel_->move(110, 10);

    productCostLabel_ = new QLabel(this);
    productCostLabel_->setText(QString::fromStdString("Стоимость товара: " + std::to_string(product_cost_)));
    productCostLabel_->setFont(font);
    productCostLabel_->setStyleSheet("color: black;");
    productCostLabel_->move(110, 10 + metrics.height() + 10);

    bestBeforeDateLabel_ = new QLabel(this);
    bestBeforeDateLabel_->setText(QString::fromStdString("Срок годности: " + std::to_string(best_before_date_)));
    bestBeforeDateLabel_->setFont(font);
    bestBeforeDateLabel_->setStyleSheet("color: black;");
    bestBeforeDateLabel_->move(110, 10 + metrics.height() + 10 + 10 + metrics.height());
}

ProductCard::~ProductCard() {
    delete imageLabel_;
    delete productLabel_;
}
