#include "MainWindow.hpp"

MainWindow::MainWindow(): QMainWindow()
{
	m_sendToWindow = new SendToWindow();
	m_pyScripConfWid = new PyScriptConfigurationWindow();
	m_txtEdit = new TabTextEditor();
	m_propertiesWid = new PropertiesWindow();
	m_pyScriptConfDock = new QDockWidget();
	m_propertiesDock = new QDockWidget();

	m_file = menuBar()->addMenu("&File");
	m_quit = new QAction("&Quit", this);
	m_about = new QAction("&About", this);
	m_sendTo = new QAction("&Send To...", this);
	m_file->addAction(m_sendTo);
	m_file->addAction(m_about);
	m_file->addAction(m_quit);

	m_sciptFile = menuBar()->addMenu("&Script File");
	m_saveFile = new QAction("&Save", this);
	m_openFile = new QAction("&Open File", this);
	m_newFile = new QAction("&New File", this);
	m_closeFile = new QAction("&Close File", this);
	m_saveAsFile = new QAction("Save &As", this);
	m_sciptFile->addAction(m_newFile);
	m_sciptFile->addAction(m_openFile);
	m_sciptFile->addAction(m_saveFile);
	m_sciptFile->addAction(m_closeFile);
	m_sciptFile->addAction(m_saveAsFile);

	m_confFile = menuBar()->addMenu("&Config File");
	m_saveConfigFile = new QAction("&Save", this);
	m_openConfigFile = new QAction("&Open File", this);
	m_newConfigFile = new QAction("&New File", this);
	m_closeConfigFile = new QAction("&Close File", this);
	m_saveAsConfigFile = new QAction("Save &As", this);
	m_confFile->addAction(m_newConfigFile);
	m_confFile->addAction(m_openConfigFile);
	m_confFile->addAction(m_saveConfigFile);
	m_confFile->addAction(m_closeConfigFile);
	m_confFile->addAction(m_saveAsConfigFile);

	m_pyScriptConfDock->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
	m_propertiesDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);

	addDockWidget(Qt::RightDockWidgetArea, m_propertiesDock);
	addDockWidget(Qt::RightDockWidgetArea, m_pyScriptConfDock);

	m_propertiesDock->setWidget(m_propertiesWid);
	m_pyScriptConfDock->setWidget(m_pyScripConfWid);

	setCentralWidget(m_txtEdit);

	m_newFile->setShortcut(QKeySequence("Ctrl+n"));
	m_closeFile->setShortcut(QKeySequence("Ctrl+w"));
	m_openFile->setShortcut(QKeySequence("Ctrl+o"));
	m_saveFile->setShortcut(QKeySequence("Ctrl+s"));
	m_quit->setShortcut(QKeySequence("Ctrl+q"));

	QObject::connect(m_newFile, SIGNAL(triggered()), m_txtEdit, SLOT(makeTextEditor()));
	QObject::connect(m_closeFile, SIGNAL(triggered()), m_txtEdit, SLOT(closeCurrentTab()));
	QObject::connect(m_openFile, SIGNAL(triggered()), this, SLOT(openFile()));
	QObject::connect(m_saveFile, SIGNAL(triggered()), m_txtEdit, SLOT(saveCurrentFile()));
	QObject::connect(m_saveAsFile, SIGNAL(triggered()), m_txtEdit, SLOT(saveCurrentFileAs()));

	QObject::connect(m_saveAsConfigFile, SIGNAL(triggered()), this, SLOT(saveAsConfigFile()));
	QObject::connect(m_saveConfigFile, SIGNAL(triggered()), this, SLOT(saveConfigFile()));
	QObject::connect(m_openConfigFile, SIGNAL(triggered()), this, SLOT(openConfigFile()));

	QObject::connect(m_quit, SIGNAL(triggered()), qApp, SLOT(quit()));
	QObject::connect(m_sendTo, SIGNAL(triggered()), this, SLOT(runSendWind()));
}

MainWindow::~MainWindow()
{
	delete m_pyScripConfWid;
	delete m_txtEdit;
	delete m_propertiesWid;
	delete m_pyScriptConfDock;
	delete m_propertiesDock;
	delete m_sciptFile;
	delete m_confFile;
	delete m_saveFile;
	delete m_newFile;
	delete m_openFile;
	delete m_closeFile;
	delete m_saveConfigFile;
	delete m_newConfigFile;
	delete m_openConfigFile;
	delete m_closeConfigFile;
	delete m_saveAsConfigFile;
	delete m_quit;
	delete m_about;
	delete m_sendTo;
	delete m_file;
	delete m_sendToWindow;
}

void MainWindow::openFile()
{
	QUrl path(QFileDialog::getOpenFileName(this));
	m_txtEdit->makeTextEditor(path);
}

void MainWindow::saveAsConfigFile()
{
	QUrl path(QFileDialog::getSaveFileName(this));
	Parsser::setFilePath(path.path().toStdString());
	m_pyScripConfWid->setEditConfigFilePath(path.path());
	ofstream out(path.path().toStdString());
	auto root = Parsser::readConfigFile();
	out << root;
}

void MainWindow::saveConfigFile()
{
	m_pyScripConfWid->save();
	m_propertiesWid->save();
}

void MainWindow::openConfigFile()
{
	QString configFilePath = QFileDialog::getOpenFileName(this);
	std::cout<<"value of path"<<configFilePath.toStdString()<<std::endl;
	
	if(configFilePath != "")
	{
		m_pyScripConfWid->setEditConfigFilePath(configFilePath);
		Parsser::setFilePath(configFilePath.toStdString());
		m_pyScripConfWid->loadData();
		m_propertiesWid->loadData();
	}
}

void MainWindow::runSendWind()
{
	m_sendToWindow->showWind(QUrl(m_pyScripConfWid->getEditConfifFilePath()));
}