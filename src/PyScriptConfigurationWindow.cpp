#include "PyScriptConfigurationWindow.hpp"

PyScriptConfigurationWindow::PyScriptConfigurationWindow(): QWidget()
{
	m_vbox = new QVBoxLayout();
	m_hbox = new QHBoxLayout();
	m_hbox2 = new QHBoxLayout();
	m_tab = new QTabWidget();
	m_tab->setGeometry(30, 20, 480, 320);

	m_frontWindLeaf = new HandlerConfLeaf(FRONT_WIND);
	m_sideWindLeaf = new HandlerConfLeaf(SIDE_WIND);
	m_backWindLeaf = new HandlerConfLeaf(BACK_WIND);
	m_pathConfigLeaf = new PathConfigLeaf();

	m_cancelButton = new QPushButton("Cancel");
	m_okButton = new QPushButton("Save");

	m_exploreConfigFileButton = new QPushButton("...");
	m_editConfigFilePath = new QLineEdit();
	m_configFilePathLabel = new QLabel("Config file path");

	m_tab->addTab(m_pathConfigLeaf, "General");
	m_tab->addTab(m_frontWindLeaf, "Front Wind");
	m_tab->addTab(m_sideWindLeaf, "Side Wind");
	m_tab->addTab(m_backWindLeaf, "Back Wind");

	m_hbox->addWidget(m_cancelButton);
	m_hbox->addWidget(m_okButton);

	m_hbox2->addWidget(m_configFilePathLabel);
	m_hbox2->addWidget(m_editConfigFilePath);
	m_hbox2->addWidget(m_exploreConfigFileButton);

	m_vbox->addWidget(m_tab);
	m_vbox->addLayout(m_hbox2);
	m_vbox->addLayout(m_hbox);

	this->setLayout(m_vbox);

	QObject::connect(m_cancelButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(m_okButton, SIGNAL(clicked()), this, SLOT(save()));
	QObject::connect(m_exploreConfigFileButton, SIGNAL(clicked()), this, SLOT(collectConfigFilePath()));
}

PyScriptConfigurationWindow::~PyScriptConfigurationWindow()
{
	delete m_frontWindLeaf;
	delete m_sideWindLeaf;
	delete m_backWindLeaf;
	delete m_exploreConfigFileButton;
	delete m_editConfigFilePath;
	delete m_tab;
}

void PyScriptConfigurationWindow::save()
{
	Parsser::writeConfig("ScriptPath", (m_pathConfigLeaf->getScriptPath()).toStdString());

	Parsser::writeConfig("HelmHandlerSideWindPyScript", (m_sideWindLeaf->getScriptNameHelm()).toStdString());
	Parsser::writeConfig("SailHandlerSideWindPyScript", (m_sideWindLeaf->getScriptNameSail()).toStdString());
	Parsser::writeConfig("EnableHelmHandlerSideWindPyScript", (m_sideWindLeaf->getEnablePyScriptHelm()));
	Parsser::writeConfig("EnableSailHandlerSideWindPyScript", (m_sideWindLeaf->getEnablePyScriptSail()));

	Parsser::writeConfig("HelmHandlerFrontWindPyScript", (m_frontWindLeaf->getScriptNameHelm()).toStdString());
	Parsser::writeConfig("SailHandlerFrontWindPyScript", (m_frontWindLeaf->getScriptNameSail()).toStdString());
	Parsser::writeConfig("EnableHelmHandlerFrontWindPyScript", (m_frontWindLeaf->getEnablePyScriptHelm()));
	Parsser::writeConfig("EnableSailHandlerFrontWindPyScript", (m_frontWindLeaf->getEnablePyScriptSail()));

	Parsser::writeConfig("HelmHandlerBackWindPyScript", (m_backWindLeaf->getScriptNameHelm()).toStdString());
	Parsser::writeConfig("SailHandlerBackWindPyScript", (m_backWindLeaf->getScriptNameSail()).toStdString());
	Parsser::writeConfig("EnableHelmHandlerBackWindPyScript", (m_backWindLeaf->getEnablePyScriptHelm()));
	Parsser::writeConfig("EnableSailHandlerBackWindPyScript", (m_backWindLeaf->getEnablePyScriptSail()));
}

void PyScriptConfigurationWindow::collectConfigFilePath()
{
	m_configFilePath = QFileDialog::getOpenFileName(this);

	m_editConfigFilePath->setText(m_configFilePath);
	Parsser::setFilePath(m_configFilePath.toStdString());

	m_pathConfigLeaf->setSciptPath(QString((Parsser::readConfigStr("ScriptPath")).c_str()));

	m_sideWindLeaf->setScriptNameHelm(QString((Parsser::readConfigStr("HelmHandlerSideWindPyScript")).c_str()));
	m_sideWindLeaf->setScriptNameSail(QString((Parsser::readConfigStr("SailHandlerSideWindPyScript")).c_str()));
	m_sideWindLeaf->setEnablePyScriptHelm(Parsser::readConfigBool("EnableHelmHandlerSideWindPyScript"));
	m_sideWindLeaf->setEnablePyScriptSail(Parsser::readConfigBool("EnableSailHandlerSideWindPyScript"));

	m_frontWindLeaf->setScriptNameHelm(QString((Parsser::readConfigStr("HelmHandlerFrontWindPyScript")).c_str()));
	m_frontWindLeaf->setScriptNameSail(QString((Parsser::readConfigStr("SailHandlerFrontWindPyScript")).c_str()));
	m_frontWindLeaf->setEnablePyScriptHelm(Parsser::readConfigBool("EnableHelmHandlerFrontWindPyScript"));
	m_frontWindLeaf->setEnablePyScriptSail(Parsser::readConfigBool("EnableSailHandlerFrontWindPyScript"));

	m_backWindLeaf->setScriptNameHelm(QString((Parsser::readConfigStr("HelmHandlerBackWindPyScript")).c_str()));
	m_backWindLeaf->setScriptNameSail(QString((Parsser::readConfigStr("SailHandlerBackWindPyScript")).c_str()));
	m_backWindLeaf->setEnablePyScriptHelm(Parsser::readConfigBool("EnableHelmHandlerBackWindPyScript"));
	m_backWindLeaf->setEnablePyScriptSail(Parsser::readConfigBool("EnableSailHandlerSideWindPyScript"));

	cout<<"enable "<<m_backWindLeaf->getEnablePyScriptHelm()<<endl;
}