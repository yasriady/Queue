#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent)
    : QStatusBar(parent)
{
    m_sbWidget = new StatusBarWidget(this);
    addPermanentWidget(m_sbWidget, 1);
}

StatusBarWidget *StatusBar::sbWidget() const
{
    return m_sbWidget;
}
