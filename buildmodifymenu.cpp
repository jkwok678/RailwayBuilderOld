#include "buildmodifymenu.h"

BuildModifyMenu::BuildModifyMenu()
{
    overallBuildModifyMenu = new QVBoxLayout;
    buildModifyMenuPart1 = new QHBoxLayout;
    trackMenuButton = new QToolButton;
    trackMenuButton->setIcon(QIcon(":/icons/buildMenuIcon.png"));
    buildModifyMenuPart1->addWidget(trackMenuButton);
    overallBuildModifyMenu->addLayout(buildModifyMenuPart1);

}
