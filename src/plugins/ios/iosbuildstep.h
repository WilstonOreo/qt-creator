/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include <projectexplorer/abstractprocessstep.h>

QT_BEGIN_NAMESPACE
class QListWidgetItem;
QT_END_NAMESPACE

namespace Ios {
namespace Internal {

class IosBuildStepConfigWidget;
class IosBuildStepFactory;

class IosBuildStep : public ProjectExplorer::AbstractProcessStep
{
    Q_OBJECT

    friend class IosBuildStepConfigWidget;
    friend class IosBuildStepFactory;

public:
    IosBuildStep(ProjectExplorer::BuildStepList *parent, Core::Id id);

    ProjectExplorer::BuildStepConfigWidget *createConfigWidget() override;
    void setBaseArguments(const QStringList &args);
    void setExtraArguments(const QStringList &extraArgs);
    QStringList baseArguments() const;
    QStringList allArguments() const;
    QStringList defaultArguments() const;
    Utils::FilePath buildCommand() const;

private:
    bool init() override;
    void doRun() override;
    bool fromMap(const QVariantMap &map) override;
    QVariantMap toMap() const override;

    QStringList m_baseBuildArguments;
    QStringList m_extraArguments;
    bool m_useDefaultArguments = true;
    bool m_clean = false;
};

class IosBuildStepFactory : public ProjectExplorer::BuildStepFactory
{
public:
    IosBuildStepFactory();
};

} // namespace Internal
} // namespace Ios
