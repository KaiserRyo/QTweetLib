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

#include <QSharedData>
#include <QDateTime>
#include "qtweetstatus.h"
#include "qtweetuser.h"
#include "qtweetplace.h"
#include "qtweetentityurl.h"
#include "qtweetentityhashtag.h"
#include "qtweetentityusermentions.h"
#include "qtweetentitymedia.h"

class QTweetStatusData : public QSharedData
{
public:
    QTweetStatusData() : id(0), inReplyToStatusId(0), retweetedStatus(0) {}

    QTweetStatusData(const QTweetStatusData& other) : QSharedData(other)
    {
        id = other.id;
        text = other.text;
        createdAt = other.createdAt;
        inReplyToUserId = other.inReplyToUserId;
        inReplyToScreenName = other.inReplyToScreenName;
        inReplyToStatusId = other.inReplyToStatusId;
        retweetCount = other.retweetCount;
        favorited = other.favorited;
        retweeted = other.retweeted;
        source = other.source;
        user = other.user;
        place = other.place;

        if (other.retweetedStatus) {
            retweetedStatus = new QTweetStatus(*other.retweetedStatus);
        } else {
            retweetedStatus = 0;
        }
        urlEntities = other.urlEntities;
        hashtagEntities = other.hashtagEntities;
        userMentionEntities = other.userMentionEntities;
        mediaEntities = other.mediaEntities;
        lastUpdate = other.lastUpdate;
        currentUserRetweetId = other.currentUserRetweetId;
    }

    ~QTweetStatusData()
    {
        delete retweetedStatus;
    }

    qint64 id;
    QString text;
    QDateTime createdAt;
    qint64 inReplyToUserId;
    QString inReplyToScreenName;
    qint64 inReplyToStatusId;
    int retweetCount;
    bool favorited;
    bool retweeted;
    QString source;
    QTweetUser user;
    QTweetPlace place;
    QTweetStatus *retweetedStatus;
    QList<QTweetEntityUrl> urlEntities;
    QList<QTweetEntityHashtag> hashtagEntities;
    QList<QTweetEntityUserMentions> userMentionEntities;
    QList<QTweetEntityMedia> mediaEntities;
    QDateTime lastUpdate;
    qint64 currentUserRetweetId;
};

QTweetStatus::QTweetStatus() :
        d(new QTweetStatusData)
{
}

QTweetStatus::QTweetStatus(const QTweetStatus &other) :
        d(other.d)
{
}

QTweetStatus& QTweetStatus::operator=(const QTweetStatus &rhs)
{
    if (this != &rhs)
        d.operator=(rhs.d);
    return *this;
}

QTweetStatus::~QTweetStatus()
{
}

void QTweetStatus::setId(qint64 id)
{
    d->id = id;
}

qint64 QTweetStatus::id() const
{
    return d->id;
}

void QTweetStatus::setText(const QString &text)
{
    d->text = text;
}

QString QTweetStatus::text() const
{
    return d->text;
}

void QTweetStatus::setCreatedAt(const QString &twitterDate)
{
    d->createdAt = QTweetUser::twitterDateToQDateTime(twitterDate);
}

void QTweetStatus::setCreatedAt(const QDateTime &dateTime)
{
    d->createdAt = dateTime;
}

QDateTime QTweetStatus::createdAt() const
{
    return d->createdAt;
}

void QTweetStatus::setInReplyToUserId(qint64 id)
{
    d->inReplyToUserId = id;
}

qint64 QTweetStatus::inReplyToUserId() const
{
    return d->inReplyToUserId;
}

void QTweetStatus::setInReplyToScreenName(const QString &screenName)
{
    d->inReplyToScreenName = screenName;
}

QString QTweetStatus::inReplyToScreenName() const
{
    return d->inReplyToScreenName;
}

void QTweetStatus::setInReplyToStatusId(qint64 id)
{
    d->inReplyToStatusId = id;
}

qint64 QTweetStatus::inReplyToStatusId() const
{
    return d->inReplyToStatusId;
}

void QTweetStatus::setFavorited(bool fav)
{
    d->favorited = fav;
}

bool QTweetStatus::favorited() const
{
    return d->favorited;
}

void QTweetStatus::setSource(const QString &source)
{
    d->source = source;
}

QString QTweetStatus::source() const
{
    return d->source;
}

void QTweetStatus::setUser(const QTweetUser &user)
{
    d->user = user;
}

QTweetUser QTweetStatus::user() const
{
    return d->user;
}

qint64 QTweetStatus::userid() const
{
    return d->user.id();
}

void QTweetStatus::setRetweetedStatus(const QTweetStatus &status)
{
    if (!d->retweetedStatus)
        d->retweetedStatus = new QTweetStatus;

    *d->retweetedStatus = status;
}

QTweetStatus QTweetStatus::retweetedStatus() const
{
    if (!d->retweetedStatus)
        return QTweetStatus();

    return *d->retweetedStatus;
}

void QTweetStatus::setPlace(const QTweetPlace &place)
{
    d->place = place;
}

QTweetPlace QTweetStatus::place() const
{
    return d->place;
}

void QTweetStatus::setRetweet(bool retweeted)
{
	d->retweeted = retweeted;
}

bool QTweetStatus::isRetweet() const
{
	return d->retweeted;
}

void QTweetStatus::setRetweetCount(int retweetCount)
{
	d->retweetCount = retweetCount;
}

int QTweetStatus::getRetweetCount() const
{
	return d->retweetCount;
}

QList<QTweetEntityUrl> QTweetStatus::urlEntities() const
{
    return d->urlEntities;
}

QList<QTweetEntityHashtag> QTweetStatus::hashtagEntities() const
{
    return d->hashtagEntities;
}

QList<QTweetEntityUserMentions> QTweetStatus::userMentionsEntities() const
{
    return d->userMentionEntities;
}

QList<QTweetEntityMedia> QTweetStatus::mediaEntities() const
{
    return d->mediaEntities;
}

void QTweetStatus::addUrlEntity(const QTweetEntityUrl &urlEntity)
{
    d->urlEntities.append(urlEntity);
}

void QTweetStatus::addHashtagEntity(const QTweetEntityHashtag &hashtagEntity)
{
    d->hashtagEntities.append(hashtagEntity);
}

void QTweetStatus::addUserMentionsEntity(const QTweetEntityUserMentions &userMentionsEntity)
{
    d->userMentionEntities.append(userMentionsEntity);
}

void QTweetStatus::addMediaEntity(const QTweetEntityMedia &mediaEntity)
{
    d->mediaEntities.append(mediaEntity);
}
QDateTime QTweetStatus::lastUpdate() const
{
    return d->lastUpdate;
}
void QTweetStatus::setLastUpdate(const QDateTime& lastUpdate)
{
    d->lastUpdate = lastUpdate;
}

void QTweetStatus::setCurrentUserRetweetId(qint64 currentUserRetweetId)
{
    d->currentUserRetweetId = currentUserRetweetId;
}

qint64 QTweetStatus::currentUserRetweetId() const
{
    return d->currentUserRetweetId;
}
