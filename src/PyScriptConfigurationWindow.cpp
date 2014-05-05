#include "PyScriptConfigurationWindow.hpp"

PyScriptConfigurationWindow::PyScriptConfigurationWindow(): QWidget()
{
	m_vbox = new QVBoxLayout();
	m_hbox = new QHBoxLayout();
	m_tab = new QTabWidget();
	m_tab->setGeometry(30, 20, 480, 320);

	m_frontWindLeaf = new HandlerConfLeaf(FRONT_WIND);
	m_sideWindLeaf = new HandlerConfLeaf(SIDE_WIND);
	m_backWindLeaf = new HandlerConfLeaf(BACK_WIND);

	m_cancelButton = new QPushButton("Cancel");
	m_okButton = new QPushButton("Ok");

	m_tab->addTab(m_frontWindLeaf, "Front Wind");
	m_tab->addTab(m_sideWindLeaf, "Side Wind");
	m_tab->addTab(m_backWindLeaf, "Back Wind");

	m_hbox->addWidget(m_cancelButton);
	m_hbox->addWidget(m_okButton);

	m_vbox->addWidget(m_tab);
	m_vbox->addLayout(m_hbox);

	this->setLayout(m_vbox);

	QObject::connect(m_cancelButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(m_okButton, SIGNAL(clicked()), this, SLOT(save()));
}

PyScriptConfigurationWindow::~PyScriptConfigurationWindow()
{
	delete m_frontWindLeaf;
	delete m_sideWindLeaf;
	delete m_backWindLeaf;
	delete m_tab;
}

void PyScriptConfigurationWindow::save()
{
	Parsser::writeConfig("HelmHandlerSideWindPyScript", m_sideWindLeaf->getScriptNameHelm());
	Parsser::writeConfig("SailHandlerSideWindPyScript", m_sideWindLeaf->getScriptNameSail());

	Parsser::writeConfig("HelmHandlerFrontWindPyScript", m_frontWindLeaf->getScriptNameHelm());
	Parsser::writeConfig("SailHandlerFrontWindPyScript", m_frontWindLeaf->getScriptNameSail());

	Parsser::writeConfig("HelmHandlerBackWindPyScript", m_backWindLeaf->getScriptNameHelm());
	Parsser::writeConfig("SailHandlerBackWindPyScript", m_backWindLeaf->getScriptNameSail());

	qApp->quit();
}