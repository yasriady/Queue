#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent)
    : DStatusBar(parent)
{
    m_sbWidget = new StatusBarWidget(this);
    addPermanentWidget(m_sbWidget, 1);
}

StatusBar::~StatusBar()
{
    delete m_sbWidget;
}

void StatusBar::updateUi()
{
    showMessage( __PRETTY_FUNCTION__ );
}

void StatusBar::showEvent(QShowEvent *)
{
    updateUi();
}

StatusBarWidget *StatusBar::sbWidget() const
{
    return m_sbWidget;
}
