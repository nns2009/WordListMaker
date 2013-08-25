#ifndef WORDLISTMAKER_H
#define WORDLISTMAKER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>

namespace Ui {
class WordListMaker;
}

class WordListMaker : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WordListMaker(QWidget *parent = 0);
    ~WordListMaker();
    
private:
    void processText(QString text);

private slots:
    void on_bOpen_clicked();

    void on_bPaste_clicked();

private:
    Ui::WordListMaker *ui;
};

#endif // WORDLISTMAKER_H
