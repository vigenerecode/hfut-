#ifndef CLOCK_H
#define CLOCK_H
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QRectF>
QT_BEGIN_NAMESPACE
namespace Ui {
class Clock;
}
QT_END_NAMESPACE
class Clock : public QWidget {
    Q_OBJECT
public:
    Clock(QWidget *parent = nullptr);
    ~Clock();
    Ui::Clock *ui;
protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);

        // 画表盘
        painter.drawEllipse(rect().center(), 100, 100);

        // 画时钟刻度
        for (int i = 1; i < 13; i++) {
            painter.save();
            painter.translate(rect().center());
            painter.rotate(i * 30.0); // 每个小时刻度30度
            painter.drawText(QRectF(-8, -100, 20, 20), Qt::AlignCenter, QString::number(i));
            painter.restore();
        }

        // 画时针
        painter.save();
        painter.translate(rect().center());
        painter.rotate(30 * (time.hour() % 12 + time.minute() / 60.0));
        painter.drawLine(0, 0, 0, -40);
        painter.restore();

        // 画分针
        painter.save();
        painter.translate(rect().center());
        painter.rotate(6 * (time.minute() + time.second() / 60.0));
        painter.drawLine(0, 0, 0, -60);
        painter.restore();

        // 画秒针
        painter.save();
        painter.translate(rect().center());
        painter.rotate(6 * time.second());
        painter.setPen(Qt::red);
        painter.drawLine(0, 0, 0, -80);
        painter.restore();
    }

private slots:
    void updateTime() {
        time = QTime::currentTime();
        update();
    }

private:
    QTimer *timer;
    QTime time;
    QFont font;
};

#endif // CLOCK_H
