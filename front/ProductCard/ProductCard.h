//
// Created by near on 08.10.24.
//

#ifndef PRODUCTCARD_H
#define PRODUCTCARD_H
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QImage>


class ProductCard : public QLabel {
    Q_OBJECT;

public:
    ProductCard(int x, int y, QWidget *parent = nullptr, std::string path = "../front/res/noImage.jpg");

    ProductCard(QWidget *parent = nullptr);

    ~ProductCard() override;

protected:
    void paintEvent(QPaintEvent *event) {
        QPainter painter(this);
        painter.setBrush(QBrush(Qt::gray));
        painter.drawRect(this->rect());
        QLabel::paintEvent(event);
    }

private:
    int x_{}, y_{};
    QLabel *imageLabel_;
    QLabel *productLabel_;
    QLabel *productCountLabel_;
    QLabel *productCostLabel_;
    QLabel *bestBeforeDateLabel_;
    std::string path_;
    std::string name_ = "No name";
    int product_count_ = 0;
    int product_cost_ = 0;
    int best_before_date_ = 0;
};


#endif //PRODUCTCARD_H
