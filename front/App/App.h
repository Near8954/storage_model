//
// Created by near on 06.10.24.
//

#ifndef APP_H
#define APP_H
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QPainter>
#include <QPalette>
#include <QPixmap>
#include <QFontDatabase>
#include <QThread>
#include <QMessageBox>
#include <QCloseEvent>
#include "front/ProductCard/ProductCard.h"
#include <QScrollArea>
#include <vector>
#include <QVBoxLayout>

class App : public QMainWindow {
    Q_OBJECT;

public:
    App();

    ~App();

public slots:
    void mail_clicked();

    void storage_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

private:
    QLabel *mainScreen_;
    QLabel *mailScreen_;
    QLabel *storageScreen_;
    QPushButton *mailButton_;
    QPushButton *storageButton_;
    QLabel *mailLabel_;
    QLabel *storageLabel_;
    QScrollArea *scrollArea_;
    QVBoxLayout *scrollAreaLayout_;
    QWidget *scrollAreaWidget_;
    std::vector<ProductCard *> product_cards_;
    std::pair<uint16_t, uint16_t> resolution_ = {1920, 1080};
    int mail_btn_clicked_cnt_ = 0;
    int storage_btn_clicked_cnt_ = 0;
};


#endif //APP_H
