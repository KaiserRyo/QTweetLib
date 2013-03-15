/* Copyright (c) 2013 Research In Motion Limited.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/* Copyright (c) 2010, Antonie Jovanoski
 *
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact e-mail: Antonie Jovanoski <minimoog77_at_gmail.com>
 */

#ifndef RESTFRIENDSHIPLOOKUP_H
#define RESTFRIENDSHIPLOOKUP_H

#include "qtweetnetbase.h"

class RESTFriendshipExists;

class QTWEETLIBSHARED_EXPORT RESTFriendshipLookup : public QTweetNetBase
{
    Q_OBJECT
public:
    RESTFriendshipLookup(QObject *parent = 0);
    RESTFriendshipLookup(OAuthTwitter *oauthTwitter, QObject *parent = 0);
    ~RESTFriendshipLookup();
    void fetch(const QList<qint64>& userInfoList);

signals:
    void friendshipInfoFound(const QMap<qint64, bool>&);

protected slots:

    void parsingJsonFinished(const QVariant &json, bool ok, const QString &errorMsg);

private:

    bool m_usesCursoring;
};

#endif // RESTFRIENDSHIPLOOKUP_H
