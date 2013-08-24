#ifndef WORDLISTMAKER_H
#define WORDLISTMAKER_H

#include <QMainWindow>
#include <QFileDialog>

namespace Ui {
class WordListMaker;
}

class WordListMaker : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WordListMaker(QWidget *parent = 0);
    ~WordListMaker();
    
private slots:
    void on_bOpen_clicked();

private:
    Ui::WordListMaker *ui;
};

#endif // WORDLISTMAKER_H
