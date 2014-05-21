#include "SendToWindow.hpp"

SendToWindow::SendToWindow(): QWidget()
{
	m_fileTosend = nullptr;

	m_userLabel = new QLabel("User");
	m_ipLabel = new QLabel("IP");
	m_pathLabel = new QLabel("Path");

	m_userEdit = new QLineEdit();
	m_ipEdit = new QLineEdit();
	m_pathEdit = new QLineEdit();

	m_send = new QPushButton("Send");
	m_cancel = new QPushButton("Cancel");

	m_gbox = new QGridLayout();
	m_hbox = new QHBoxLayout();
	m_vbox = new QVBoxLayout();

	m_gbox->addWidget(m_userLabel, 0, 0);
	m_gbox->addWidget(m_userEdit, 0, 1);
	m_gbox->addWidget(m_ipLabel, 1, 0);
	m_gbox->addWidget(m_ipEdit, 1, 1);
	m_gbox->addWidget(m_pathLabel, 2, 0);
	m_gbox->addWidget(m_pathEdit, 2, 1);

	m_hbox->addWidget(m_cancel);
	m_hbox->addWidget(m_send);

	m_vbox->addLayout(m_gbox);
	m_vbox->addLayout(m_hbox);

	QObject::connect(m_cancel, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(m_send, SIGNAL(clicked()), this, SLOT(sendFile()));

	this->setLayout(m_vbox);
}

SendToWindow::~SendToWindow()
{
	delete m_userLabel;
	delete m_userEdit;
	delete m_ipLabel;
	delete m_ipEdit;
	delete m_pathLabel;
	delete m_pathEdit;
	delete m_hbox;
	delete m_vbox;
}

void SendToWindow::showWind(QUrl fileToSend)
{
	m_fileTosend = fileToSend;
	m_userEdit->setText(QString((Parsser::readConfigStr("CurrentUserToSend")).c_str()));
	m_ipEdit->setText(QString((Parsser::readConfigStr("CurrentIpToSend")).c_str()));
	m_pathEdit->setText(QString((Parsser::readConfigStr("CurrentPathToSend")).c_str()));
	this->show();
}

void SendToWindow::sendFile()
{
	QString str = "scp ";
	str += m_fileTosend.path();
	str += " ";
	str += m_userEdit->text();
	str += "@";
	str += m_ipEdit->text();
	str += ":";
	str += m_pathEdit->text();

	system(str.toUtf8());

	if(m_userEdit->text() != QString(Parsser::readConfigStr("CurrentUserToSend").c_str()))
	{
		Parsser::writeConfig("CurrentUserToSend", m_userEdit->text().toStdString());
	}
	if(m_ipEdit->text() != QString(Parsser::readConfigStr("CurrentIpToSend").c_str()))
	{
		Parsser::writeConfig("CurrentIpToSend", m_ipEdit->text().toStdString());
	}
	if(m_pathEdit->text() != QString(Parsser::readConfigStr("CurrentPathToSend").c_str()))
	{
		Parsser::writeConfig("CurrentPathToSend", m_pathEdit->text().toStdString());
	}

	this->close();
}