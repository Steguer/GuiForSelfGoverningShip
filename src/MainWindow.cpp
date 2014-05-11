#include "MainWindow.hpp"

MainWindow::MainWindow(): QMainWindow()
{
	m_pyScripConfWid = new PyScriptConfigurationWindow();
	m_txtEdit = new TabTextEditor();
	m_propertiesWid = new PropertiesWindow();
	m_pyScriptConfDock = new QDockWidget();
	m_propertiesDock = new QDockWidget();

	m_file = menuBar()->addMenu("&File");
	m_saveFile = new QAction("&Save", this);
	m_openFile = new QAction("&Open File", this);
	m_newFile = new QAction("&New File", this);
	m_closeFile = new QAction("&Close File", this);
	m_file->addAction(m_newFile);
	m_file->addAction(m_openFile);
	m_file->addAction(m_saveFile);
	m_file->addAction(m_closeFile);

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

	QObject::connect(m_newFile, SIGNAL(triggered()), m_txtEdit, SLOT(makeTextEditor()));
	QObject::connect(m_closeFile, SIGNAL(triggered()), m_txtEdit, SLOT(closeCurrentTab()));
	QObject::connect(m_openFile, SIGNAL(triggered()), this, SLOT(openFile()));
	QObject::connect(m_saveFile, SIGNAL(triggered()), m_txtEdit, SLOT(saveCurrentFile()));
}

MainWindow::~MainWindow()
{
	delete m_pyScripConfWid;
	delete m_txtEdit;
	delete m_propertiesWid;
	delete m_pyScriptConfDock;
	delete m_propertiesDock;
	delete m_file;
	delete m_saveFile;
	delete m_newFile;
	delete m_openFile;
	delete m_closeFile;
}

void MainWindow::openFile()
{
	QUrl path(QFileDialog::getOpenFileName(this));
	m_txtEdit->makeTextEditor(path);
}