/***********************************************************************************************************************
**
** Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#include "concatenatetreesproxymodeltest.h"

#include "concatenatetreesproxymodel.h"

#include <QAbstractItemModelTester>
#include <QStandardItemModel>

namespace tests
{
void ConcatenatateTreesProxyModelTest::autotestModel()
{
    auto modelToBeTested = std::make_unique<preferences_editor::ConcatenateTreesProxyModel>();
    new QAbstractItemModelTester(modelToBeTested.get(), QAbstractItemModelTester::FailureReportingMode::Fatal, this);
}

void ConcatenatateTreesProxyModelTest::addSourceModel()
{
    auto modelToBeTested = std::make_unique<preferences_editor::ConcatenateTreesProxyModel>();
    auto sourceModelA    = std::make_unique<QStandardItemModel>();

    modelToBeTested->addSourceModel(sourceModelA.get());
}

void ConcatenatateTreesProxyModelTest::removeSourceModel() {}

} // namespace tests

QTEST_MAIN(tests::ConcatenatateTreesProxyModelTest)
