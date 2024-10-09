#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <ctime>
#include "buy.hpp"

std::mt19937 rnd(std::time(nullptr));
int day = 1;
int money = 10000;
int k, m;

std::map<std::string, std::pair<int, int>> price_prod = {
     {"Egg", {70, 10}},
    {"Apple", {50, 10}},
    {"Milk", {70, 10}},
    {"Porridge", {75, 20}},
    {"Fish", {400, 10}},
    {"Bread", {30, 10}},
    {"Water", {20, 20}},
    {"Doshik", {20, 20}},
    {"Juice", {50, 15}},
    {"Meat", {350, 15}},
    {"Ice Cream", {80, 10}},
    {"Pasta", {60, 20}},
    {"Cheese", {120, 10}},
    {"Cupcake", {150, 10}},
    {"Tea", {100, 25}},
    {"Coffee", {200, 25}},
    {"Sweet", {120, 15}},
    {"Banana", {40, 10}},
    {"Nuts", {500, 25}},
    {"Cherry", {1500, 10}}
};


class Prod {
public:
     // Конструктор по умолчанию
     Prod()
         : delivery_date_(0), exp_date_(0), priсe_(0), markdown_(0), cnt_packaging_(5), cnt_pack_(10) {}

     // Параметризованный конструктор
     Prod(std::string name, int delivery_date, int exp_date, int price)
         :name_(name), delivery_date_(delivery_date), exp_date_(exp_date), priсe_(price), cnt_pack_(50) {}

     ~Prod() {}

     void change_markdown_(int level) {
          if (level == 1) {
               markdown_ = 10;
          } else if (level == 2) {
               markdown_ = 20;
          }
     }

     std::string name() const {
          return name_;
     }

     int delivery_date() const {
          return delivery_date_;
     }

     int exp_date() const {
          return exp_date_;
     }

     int markdown() const {
          return markdown_;
     }

     int cnt_packaging() const {
          return cnt_packaging_;
     }

     int cnt_pack() const {
          return cnt_pack_;
     }

     int price_md() const {
          return (double)priсe_ - (double)priсe_ * ((double)markdown_ / 100);
     }

     int price_buy() {
          return (double)priсe_ - (double)priсe_ * (30.f / 100.f);
     }

protected:
     std::string name_;
     int delivery_date_; // дата поставки
     int exp_date_; // срок годности
     int markdown_ = 0; // уценка
     int cnt_packaging_; //кол-во упаковок
     int cnt_pack_; // кол-во пачек в упаковке
     int priсe_; // цена
};


std::vector<Prod> products = {
     Prod("Egg", day, day + 10, 70),
     Prod("Apple", day, day + 10, 50),
     Prod("Milk", day, day + 10, 70),
     Prod("Porridge", day, day + 20, 75),
     Prod("Fish", day, day + 10, 400),
     Prod("Bread", day, day + 10, 30),
     Prod("Water", day, day + 20, 20),
     Prod("Doshik", day, day + 20, 20),
     Prod("Juice", day, day + 15, 50),
     Prod("Meat", day, day + 15, 350),
     Prod("Ice Cream", day, day + 10, 80),
     Prod("Pasta", day, day + 20, 60),
     Prod("Cheese", day, day + 10, 120),
     Prod("Cupcake", day, day + 10, 150),
     Prod("Tea", day, day + 25, 100),
     Prod("Coffee", day, day + 25, 200),
     Prod("Sweet", day, day + 15, 120),
     Prod("Banana", day, day + 10, 40),
     Prod("Nuts", day, day + 25, 500),
     Prod("Cherry", day, day + 10, 1500)
 };

bool in(std::vector<Prod>& a, std::string name) {
     for (auto i : a) {
          if (i.name() == name) {
               return true;
          }
     }
     return false;
}


std::vector<Prod> request() {
     std::vector<Prod> req;
     int q = rnd() % 10;
     if (q <= 4) {
          q = rnd() % products.size() + 1;
          req.resize(q);
          while (req.size() != q) {
               int w = rnd();
               if (!in(req, products[w].name())) {
                    std::string _name = products[w].name();
                    req.push_back(Prod(_name, day, day + price_prod[_name].second, price_prod[_name].first));
               }
          }
     }
     return req;
}


std::vector<Prod> data_requests;

void request2() {
     for (int _ = 0; _ < m; _++) {
          std::vector<Prod> add = request();
     }
}




int main()
{
     std::cin >> k >> m;
     products.resize(k);
     // shops.resize(m);
     // int cnt = 0;
     // for (auto i : shops) {
          // cnt++;
     // }
     // std::cout << cnt;
}
