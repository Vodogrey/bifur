#ifndef ITERATIONPAMING_H
#define ITERATIONPAMING_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>

#include "qcustomplot.h"
#include "iterationcalc.h"


#include <QDebug>

class iterationMaping : public QDialog
{
    Q_OBJECT
public:
    explicit iterationMaping(QWidget *parent = 0);

signals:

public slots:

private slots:
    void mouseWheel();
    void mousePress();
    void slotStartClicked();
    void rightClick(QPoint pos);
    void saveAsImage();

protected:
    void GUI();
    void addRandomGraph();
    void makeGraph();
    void clear();
    virtual void keyPressEvent(QKeyEvent *event);

private:
    QGridLayout* m_layout;

    QLineEdit* m_le_lambda;
    QLabel* m_lb_lambda;

    QLineEdit* m_le_countPoint;
    QLabel* m_lb_countPoint;

    QLineEdit* m_le_func;
    QLabel* m_lb_func;

    QLineEdit* m_le_started;
    QLabel* m_lb_started;

    QLineEdit* m_le_ended;
    QLabel* m_lb_ended;

    QLineEdit* m_le_derivative;
    QLabel* m_lb_derivative;

    QLineEdit* m_le_start_iter;
    QLabel* m_lb_start_iter;

    QPushButton* m_pb_start;

    QCustomPlot* m_plot;
    QCPCurve* m_iterCurve;

    iterationCalc* m_iterCalc;

    QString msg;// сообщение юзеру

    int countPoints=1000;
    QString lambda;
    QString countSteps; //!!
    QString s_X;//начало итерационной лестницы
    QString s_k;//начало итерационной лестницы
    QString xMin;
    QString xMax;
    QString func;
    QString derivative;

    QVector<double> abcsX;// абциса
    QVector<double> iterX;//итерационная лестница
    QVector<double> iterY;
    QVector<double> linX;//функция
    QVector<double> linY;
    QVector<double> stabX;//график устойчивых точек
    QVector<double> stabY;
};

#endif // ITERATIONPAMING_H
