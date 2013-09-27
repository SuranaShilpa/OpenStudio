/**********************************************************************
*  Copyright (c) 2008-2013, Alliance for Sustainable Energy.  
*  All rights reserved.
*  
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*  
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*  
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**********************************************************************/

#include <gtest/gtest.h>

#include <utilities/cloud/AWSProvider.hpp>
#include <utilities/cloud/AWSProvider_Impl.hpp>

#include <string>

using namespace std;
using namespace openstudio;

TEST(AWSProvider, AWSProviderTest)
{
  AWSProvider awsProvider;

  //awsProvider.serverInstanceTypes();

  //awsProvider.internetAvailable();

  //awsProvider.serviceAvailable();

  //awsProvider.validateCredentials();

  //awsProvider.resourcesAvailableToStart();

  // Takes over 1 minute
  //awsProvider.setServerInstanceType("t1.micro");
  //awsProvider.waitForServer(120000);

  //awsProvider.waitForWorkers(120000);

  //awsProvider.serverRunning();
}
