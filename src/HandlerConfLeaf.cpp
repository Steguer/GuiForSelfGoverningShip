#include "HandlerConfLeaf.hpp"

HandlerConfLeaf::HandlerConfLeaf()
{
	m_gbox = new QGridLayout;
	m_hbox = new QHBoxLayout;

	m_helmLabel = new QLabel("Helm");
	m_sailLabel = new QLabel("Sail");

	m_editPyScriptHelmName = new QLineEdit();
	m_editPyScriptSailName = new QLineEdit();

	m_exploreHelmButton = new QPushButton("...");
	m_exploreSailButton = new QPushButton("...");

	m_enablePyScript = new QLabel("Enable ");
	m_enablePyScriptHelm = new QCheckBox("helm ");
	m_enablePyScriptSail = new QCheckBox("sail ");

	m_gbox->addWidget(m_helmLabel, 0, 0);
	m_gbox->addWidget(m_editPyScriptHelmName, 0, 1);
	m_gbox->addWidget(m_exploreHelmButton, 0, 2);

	m_gbox->addWidget(m_sailLabel, 1, 0);
	m_gbox->addWidget(m_editPyScriptSailName, 1, 1);
	m_gbox->addWidget(m_exploreSailButton, 1, 2);

	m_gbox->addWidget(m_enablePyScript, 2, 0);
	m_hbox->addWidget(m_enablePyScriptSail);
	m_hbox->addWidget(m_enablePyScriptHelm);
	m_gbox->addLayout(m_hbox, 2, 1);

	this->setLayout(m_gbox);

	QObject::connect(m_exploreHelmButton, SIGNAL(clicked()), this, SLOT(collectScriptNameHelm()));
	QObject::connect(m_exploreSailButton, SIGNAL(clicked()), this, SLOT(collectScriptNameSail()));
}

HandlerConfLeaf::HandlerConfLeaf(WindDirection dir): HandlerConfLeaf()
{

	switch(dir)
	{
		case SIDE_WIND:
			m_editPyScriptHelmName->setText(QString((Parsser::readConfigStr("HelmHandlerSideWindPyScript")).c_str()));
			m_editPyScriptSailName->setText(QString((Parsser::readConfigStr("SailHandlerSideWindPyScript")).c_str()));
			break;
		case FRONT_WIND:
			m_editPyScriptHelmName->setText(QString((Parsser::readConfigStr("HelmHandlerFrontWindPyScript")).c_str()));
			m_editPyScriptSailName->setText(QString((Parsser::readConfigStr("SailHandlerFrontWindPyScript")).c_str()));
			break;
		case BACK_WIND:
			m_editPyScriptHelmName->setText(QString((Parsser::readConfigStr("HelmHandlerBackWindPyScript")).c_str()));
			m_editPyScriptSailName->setText(QString((Parsser::readConfigStr("SailHandlerBackWindPyScript")).c_str()));
			break;
		default:
			break;
			
	}
}

HandlerConfLeaf::~HandlerConfLeaf()
{
	delete m_gbox;
	delete m_helmLabel;
	delete m_sailLabel;
	delete m_editPyScriptHelmName;
	delete m_editPyScriptHelmName;
	delete m_exploreHelmButton;
	delete m_exploreSailButton;
	delete m_enablePyScriptHelm;
	delete m_enablePyScriptSail;
	delete m_enablePyScript;
	delete m_hbox;
}

void HandlerConfLeaf::collectScriptNameHelm()
{
	m_scriptHelmName = (((QFileDialog::getOpenFileName(this).split("/")).last()).split(".")).first();
	m_editPyScriptHelmName->setText(m_scriptHelmName);
}

void HandlerConfLeaf::collectScriptNameSail()
{
	m_scriptSailName = (((QFileDialog::getOpenFileName(this).split("/")).last()).split(".")).first();
	m_editPyScriptSailName->setText(m_scriptSailName);
}

QString HandlerConfLeaf::getScriptNameHelm() const
{
	return m_editPyScriptHelmName->text();
}

QString HandlerConfLeaf::getScriptNameSail() const
{
	return m_editPyScriptSailName->text();
}

void HandlerConfLeaf::setScriptNameHelm(QString const& name)
{
	m_editPyScriptHelmName->setText(name);
}

void HandlerConfLeaf::setScriptNameSail(QString const& name)
{
	m_editPyScriptSailName->setText(name);
}

bool HandlerConfLeaf::getEnablePyScriptHelm()
{
	return m_enablePyScriptHelm->isChecked();
}

bool HandlerConfLeaf::getEnablePyScriptSail()
{
	return m_enablePyScriptSail->isChecked();
}

void HandlerConfLeaf::setEnablePyScriptHelm(bool const& ena)
{
	m_enablePyScriptHelm->setChecked(ena);
}

void HandlerConfLeaf::setEnablePyScriptSail(bool const& ena)
{
	m_enablePyScriptSail->setChecked(ena);
}