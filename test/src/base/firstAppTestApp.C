//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "firstAppTestApp.h"
#include "firstAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<firstAppTestApp>()
{
  InputParameters params = validParams<firstAppApp>();
  return params;
}

firstAppTestApp::firstAppTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  firstAppApp::registerObjectDepends(_factory);
  firstAppApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  firstAppApp::associateSyntaxDepends(_syntax, _action_factory);
  firstAppApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  firstAppApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    firstAppTestApp::registerObjects(_factory);
    firstAppTestApp::associateSyntax(_syntax, _action_factory);
    firstAppTestApp::registerExecFlags(_factory);
  }
}

firstAppTestApp::~firstAppTestApp() {}

void
firstAppTestApp::registerApps()
{
  registerApp(firstAppApp);
  registerApp(firstAppTestApp);
}

void
firstAppTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
firstAppTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
firstAppTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
firstAppTestApp__registerApps()
{
  firstAppTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
firstAppTestApp__registerObjects(Factory & factory)
{
  firstAppTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
firstAppTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  firstAppTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
firstAppTestApp__registerExecFlags(Factory & factory)
{
  firstAppTestApp::registerExecFlags(factory);
}
