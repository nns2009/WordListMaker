#include "wordlistmaker.h"
#include "ui_wordlistmaker.h"

WordListMaker::WordListMaker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordListMaker)
{
    ui->setupUi(this);

    ui->wordList->setSortingEnabled(true);
}

WordListMaker::~WordListMaker()
{
    delete ui;
}

void WordListMaker::on_bOpen_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose text file");
    if (filename.isEmpty()) return;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open the file!";
        return;
    }
    QTextStream stream(&file);
    QString text = stream.readAll();
    file.close();
    if (stream.status() != QTextStream::Ok)
    {
        qDebug() << "Error reading file!";
        return;
    }
    qDebug() << filename;
    this->processText(text);
}
void WordListMaker::on_bPaste_clicked()
{

}

void WordListMaker::processText(QString text)
{
    //qDebug() << text;
    text = text.trimmed();
    //qDebug() << text;
    text = text.replace(QRegExp("[\\W\\d_]+"), " ");
    //qDebug() << text;
    text = text.toLower();
    //qDebug() << text;
    QStringList words = text.split(' ');
    //qDebug() << words;

    QMap<QString, int> counter;
    foreach (QString word, words)
    {
        if (word.isEmpty()) continue;

        if (counter.contains(word)) counter[word]++;
        else counter[word] = 1;
    }
    ui->nTopWordsToExclude->setEnabled(true);
    ui->nWordsInList->setEnabled(true);
    ui->tTotalWords->setEnabled(true);
    ui->wordList->setEnabled(true);

    ui->tTotalWords->setText(QString::number(counter.count()));

    ui->wordList->clear();
    ui->wordList->setRowCount(counter.count());
    ui->wordList->setColumnCount(2);
    ui->wordList->setHorizontalHeaderItem(0, new QTableWidgetItem("Word"));
    ui->wordList->setHorizontalHeaderItem(1, new QTableWidgetItem("Quantity"));

    int i = 0;
    for (QMap<QString, int>::iterator it = counter.begin(); it != counter.end(); it++)
    {
        ui->wordList->setItem(i, 0, new QTableWidgetItem(it.key()));
        ui->wordList->setItem(i, 1, new QTableWidgetItem(QString::number(it.value()) ));
        ui->wordList->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i + 1)));
        i++;
    }
    /*for (int i = 0; i < words.count(); i++)
    {
        ui->wordList->setItem(i, 0, new QTableWidgetItem(words[i]));
        ui->wordList->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i + 1)));
    }*/
}

