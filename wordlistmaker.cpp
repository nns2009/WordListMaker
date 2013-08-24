#include "wordlistmaker.h"
#include "ui_wordlistmaker.h"

WordListMaker::WordListMaker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordListMaker)
{
    ui->setupUi(this);
}

WordListMaker::~WordListMaker()
{
    delete ui;
}

void WordListMaker::on_bOpen_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose text file");
    this->ui->tTotalWords->setText(filename);
}
