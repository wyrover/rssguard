// This file is part of RSS Guard.
//
// Copyright (C) 2011-2015 by Martin Rotter <rotter.martinos@gmail.com>
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

#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QMessageBox>
#include <QDialogButtonBox>


class MessageBox : public QMessageBox {
    Q_OBJECT

  public:
    // Constructors and destructors.
    explicit MessageBox(QWidget *parent = 0);
    virtual ~MessageBox();

    // Custom icon setting.
    void setIcon(Icon icon);

    // Displays custom message box.
    static QMessageBox::StandardButton show(QWidget *parent,
                                            QMessageBox::Icon icon,
                                            const QString &title,
                                            const QString &text,
                                            const QString &informative_text = QString(),
                                            const QString &detailed_text = QString(),
                                            QMessageBox::StandardButtons buttons = QMessageBox::Ok,
                                            QMessageBox::StandardButton default_button = QMessageBox::Ok);

    static QIcon iconForStatus(QMessageBox::Icon status);

#if defined(Q_OS_OS2)
    // Performs icon replacements for given button box.
    static void iconify(QDialogButtonBox *button_box);

    // Returns icons for standard roles/statuses.
    static QIcon iconForRole(QDialogButtonBox::StandardButton button);
#endif
};

#endif // MESSAGEBOX_H
