/*************************************************************************************
 *  Copyright (C) 2012 by Alejandro Fiestas Olivares <afiestas@kde.org>              *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/

#ifndef XRANDR_BACKEND_H
#define XRANDR_BACKEND_H

#include "xlibandxrandr.h"
#include "../abstractbackend.h"

#include <QtCore/QSize>

namespace KScreen {
    class Output;
}

class XRandR : public QObject, public AbstractBackend
{
    Q_OBJECT
    Q_INTERFACES(AbstractBackend)

    public:
        explicit XRandR(QObject* parent = 0);
        virtual ~XRandR();

        virtual QString name() const;
        virtual KScreen::Config* config() const;
        virtual void setConfig(KScreen::Config* config) const;
        virtual bool isValid() const;

    private:
        QSize screenSize(KScreen::Config* config) const;
        bool setScreenSize(const QSize& size) const;
        void setPrimaryOutput(int outputId) const;
        void disableOutput(KScreen::Output* output) const;
        void enableOutput(KScreen::Output* output) const;
        void changeOutput(KScreen::Output* output, int crtcId) const;

        RRCrtc outputCrtc(int outputId) const;
        quint8* outputEdid(int outputId, size_t &len) const;
        RRCrtc freeCrtc() const;
        XRRScreenResources* screenResources() const;
        XRROutputInfo* XRROutput(int outputId) const;
        XRRCrtcInfo* XRRCrtc(int crtcId) const;

    private:
        quint8* getXProperty(Display *dpy, RROutput output, Atom atom, size_t &len) const;

        int m_screen;
        Display* m_display;
        Window m_rootWindow;
};

#endif //XRandR_BACKEND_H