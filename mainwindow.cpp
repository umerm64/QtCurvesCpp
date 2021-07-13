#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::update_ui()
{
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->spinInterval->setValue(this->ui->renderArea->intervalLength());
    this->ui->spinCount->setValue(this->ui->renderArea->stepCount());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
}


void MainWindow::on_spinInterval_valueChanged(double interval_length)
{
    this->ui->renderArea->setIntervalLength(interval_length);
}


void MainWindow::on_spinCount_valueChanged(int step_count)
{
    this->ui->renderArea->setStepCount(step_count);
}


void MainWindow::on_btnBackground_clicked()
{
    //open color picker dialog and change the button's color
    QColor color = QColorDialog::getColor(ui->renderArea->backgroundColor(), this, "Select Color");
    ui->renderArea->setBackgroundColor(color);
}


void MainWindow::on_btnLineColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderArea->shapeColor(), this, "Select Color");
    ui->renderArea->setShapeColor(color);
}


void MainWindow::on_btnCircle_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Circle);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_btnEllipse_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Ellipse);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_btnFancy_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Fancy);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_btnStarfish_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Starfish);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_btnCloud1_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud1);
    this->ui->renderArea->repaint();

    update_ui();
}


void MainWindow::on_btnCloud2_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cloud2);
    this->ui->renderArea->repaint();

    update_ui();
}

