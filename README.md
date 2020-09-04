struct pig{
    double w;
    int boughtyear,boughtday,type;
};
    QVector <pig> pigs[100];
    int currentpighome,currentmonth,maxlockpighome,gold;
    int buffprice=100,buffspeed=100,maxpigcancell=1000;
    int pighomestoretype[105];
    int sciencemap[2][15];
    int scx,scy;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //为存档案件添加的
    QMenu* load_menu=new QMenu;
    QAction* loadlateset = new QAction("读取存档");
    QAction* resetdata = new QAction("重置存档");
    load_menu->addAction(loadlateset);
    load_menu->addAction(resetdata);
    ui->Qbtnloadgame->setMenu(load_menu);
    QObject::connect(loadlateset, SIGNAL(triggered(bool)), this, SLOT(on_loadgame_clicked()));
    QObject::connect(resetdata, SIGNAL(triggered(bool)), this, SLOT(on_reset_clicked()));
    canexit=1;


    setAllbutadisappear();
    nullmovie=new QMovie;
    bigpig=new QMovie;
    bigpig->setFileName(":/new/buta/Resource/bigpigr.gif");
    blackpig=new QMovie;
    blackpig->setFileName(":/new/buta/Resource/blackpigr.gif");
    colouredpig=new QMovie;
    colouredpig->setFileName(":/new/buta/Resource/colouredpigr.gif");
    //猪移动的计时器
   /* QTimer *QButaMover=new QTimer(this);
    //QButaMover = new QTimer(this);   //新建定时器
        if(QButaMover==NULL)
         {
        qDebug()<<"fail timer!";
        }
        else{
        connect(QButaMover,SIGNAL(timeout()),this,SLOT(on_MoveButa()));//关联定时器计满信号和相应的槽函数
       //每隔1ms执行xytimerUpDate()函数
       qDebug()<<"This";
       QButaMover->setInterval(1000);
       QButaMover->start();
       qsrand(time(NULL));
    }
    */
    sciencemap[0][0]=1;sciencemap[1][0]=1;
    qsrand(time(NULL));
    ui->QBtnUnlockPigHome->setVisible(false);
    ui->QGoldWidget->hide();
    ui->QBirthPigMenuFrame->hide();
    ui->QTopUpMenuList->hide();
    ui->QFocus->hide();
    ui->Qshopframe->hide();
    ui->QoptionFrame->hide();
    ui->QFdata->hide();
    ui->QFsell->hide();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Qbtngameexit_clicked()
{
    QMessageBox::StandardButton reply;
        reply = QMessageBox::critical(this, "豚の夢","您确定要退出游戏吗？",QMessageBox::Yes| QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            canexit=0;
            QApplication* app;
            //QCoreApplication::exit();
            app->closeAllWindows();
        }
}

void MainWindow::on_reset_clicked()
{
    QMessageBox::StandardButton reply;
         reply = QMessageBox::critical(this, "豚の夢","重置存档讲使您失去之前的存档，确定继续吗？",QMessageBox::Yes| QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            QFile file("save.txt");
            if ( file.exists())
            {
                file.remove();
            }
        }
}

void MainWindow::on_loadgame_clicked()
{
    on_Qbtnloadthegame_clicked();
}
