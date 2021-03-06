// This file is part of RSS Guard.

//
// Copyright (C) 2011-2017 by Martin Rotter <rotter.martinos@gmail.com>
//
// RSS Guard is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RSS Guard is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RSS Guard. If not, see <http://www.gnu.org/licenses/>.

#ifndef TTRSSSERVICEROOT_H
#define TTRSSSERVICEROOT_H

#include "services/abstract/cacheforserviceroot.h"
#include "services/abstract/serviceroot.h"

#include <QCoreApplication>

class TtRssCategory;
class TtRssFeed;
class TtRssNetworkFactory;

class TtRssServiceRoot : public ServiceRoot, public CacheForServiceRoot {
  Q_OBJECT

  public:
    explicit TtRssServiceRoot(RootItem* parent = nullptr);
    virtual ~TtRssServiceRoot();

    void start(bool freshly_activated);
    void stop();
    QString code() const;
    bool canBeEdited() const;
    bool canBeDeleted() const;
    bool editViaGui();
    bool deleteViaGui();
    bool supportsFeedAdding() const;
    bool supportsCategoryAdding() const;
    QList<QAction*> serviceMenu();

    QString additionalTooltip() const;

    void saveAllCachedData(bool async = true);

    // Access to network.
    TtRssNetworkFactory* network() const;

    void saveAccountDataToDatabase();
    void updateTitle();

  public slots:
    void addNewFeed(const QString& url = QString());
    void addNewCategory();

  private:
    RootItem* obtainNewTreeForSyncIn() const;

    void loadFromDatabase();

    QAction* m_actionSyncIn;

    QList<QAction*> m_serviceMenu;
    TtRssNetworkFactory* m_network;
};

#endif // TTRSSSERVICEROOT_H
