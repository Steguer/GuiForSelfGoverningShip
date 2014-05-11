#include "PropertiesWindow.hpp"

PropertiesWindow::PropertiesWindow(): QScrollArea()
{
	m_gbox = new QGridLayout();

	auto root = Parsser::readConfigFile();

	vector<string> v = root.getMemberNames();

	for(auto &it : v)
	{
		if(root[it].isInt())
		{
			PropLine tmp_widgetItemVect;
			tmp_widgetItemVect.editText = new QLineEdit(QString::number(Parsser::readConfigInt(it)));
			tmp_widgetItemVect.label = new QLabel( QString(it.c_str()));
			m_widgetItemVect.push_back(tmp_widgetItemVect);
		}
	}

	int i=0;
	for(auto &it : m_widgetItemVect)
	{
		m_gbox->addWidget(it.label, i, 0);
		m_gbox->addWidget(it.editText, i, 1);
		++i;
	}

	setAutoFillBackground(true);
	setBackgroundRole(QPalette::Base);

	m_container = new QWidget();
	m_container->setLayout(m_gbox);
	this->setWidget(m_container);
}

PropertiesWindow::~PropertiesWindow()
{
	delete m_gbox;
	delete m_container;
}

void PropertiesWindow::save()
{
	for(auto &it : m_widgetItemVect)
	{
		Parsser::writeConfig((it.label->text()).toStdString(), (it.editText->text()).toInt());
	}

	qApp->quit();
}