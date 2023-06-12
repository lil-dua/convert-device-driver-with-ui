#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "QDebug"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnConvert, SIGNAL(clicked()), this, SLOT(onConvertClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

static QString buffer_data;

void MainWindow::onConvertClicked()
{
    //Open file of character device driver
    int des_fd = ::open("/dev/driver_chuyendoi",O_RDWR); //driver_chuyendoi
    //Check open device
    if(des_fd < 0){
        QMessageBox::critical(this, "Error", "Failed to open device file.\nPlease try again!");
        return;
    }
    char *buffer;

    QString typeNumber = "";

    //Get data from lineEdit: inputNumber
    buffer_data = ui->inputNumber->text();

    QString data_convert;
    int checkfail=0;
    char buffer_read[20];

    //Check list of convert number selected
    if(ui->comboBox->currentIndex() == 0){  //Binary -> Octal
        typeNumber = "Octal";
        data_convert = "0" + buffer_data;
        if(buffer_data.length() > 8)
        {
            checkfail=1;
        }
    }
    else if(ui->comboBox->currentIndex() == 1){ //Binary -> Decimal
        typeNumber = "Decimal";
        data_convert = "1" + buffer_data;
        if(buffer_data.length() > 8)
        {
            checkfail=1;
        }
    }
    else if(ui->comboBox->currentIndex() == 2){ //Binary -> Heximal
        typeNumber = "Heximal";
        if(buffer_data.length() > 8)
        {
            checkfail=1;
        }
        data_convert = "2" + buffer_data;
    }
    else if(ui->comboBox->currentIndex() == 3){ //Octal -> Binary
        typeNumber = "Binary";
        if(buffer_data.length() > 8)
        {
            checkfail=1;
        }
        data_convert = "3" + buffer_data;

    }
    else if(ui->comboBox->currentIndex() == 4){ //Octal -> Decimal
        typeNumber = "Decimal";
        if(buffer_data.length() > 8)
        {
            checkfail=1;
        }
        data_convert = "4" + buffer_data;

    }
    else if(ui->comboBox->currentIndex() == 5){ //Octal -> Heximal
        typeNumber = "Heximal";
            if(buffer_data.length() > 8)
            {
                checkfail=1;
            }
            data_convert = "5" + buffer_data;

    }
    else if(ui->comboBox->currentIndex() == 6){ //Heximal -> Binary
        typeNumber = "Binary";
        if(buffer_data.length() > 8)
        {
            checkfail=1;
        }
        data_convert = "6" + buffer_data;


    }
    else if(ui->comboBox->currentIndex() == 7){ //Heximal -> Octal
        typeNumber = "Octal";
        if(buffer_data.length() > 8)
        {
            checkfail=1;
        }
        data_convert = "7" + buffer_data;

    }
    else if(ui->comboBox->currentIndex() == 8){ //Heximal -> Decimal
        typeNumber = "Decimal";
        if(buffer_data.length() > 8)
        {
            checkfail=1;
        }
        data_convert = "8" + buffer_data;

    }
    if(checkfail==1){
        ::close(des_fd);
    }else{
        // Convert the QString data_convert to a local 8-bit representation
        QByteArray byteArray = data_convert.toLocal8Bit();
        // Get a pointer to the underlying character buffer of QByteArray
        buffer = byteArray.data();
        // Write the contents of the buffer to the device file descriptor
        write(des_fd,buffer,strlen(buffer));
        sleep(2);

        // Reset the buffer_read array to all null characters
        memset(buffer_read,'\0',sizeof(buffer_read));
        // Read up to 20 bytes of data from the device file descriptor into buffer_read
        read(des_fd,buffer_read,20);

        //Show result
        ui->edtTypeNumber->setText(typeNumber);
        ui->outputNumber->setText(QString::fromLocal8Bit(buffer_read));
        ::close(des_fd);
    }
}


