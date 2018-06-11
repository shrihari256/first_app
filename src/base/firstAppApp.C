#include "firstAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<firstAppApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

firstAppApp::firstAppApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  firstAppApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  firstAppApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  firstAppApp::registerExecFlags(_factory);
}

firstAppApp::~firstAppApp() {}

void
firstAppApp::registerApps()
{
  registerApp(firstAppApp);
}

void
firstAppApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"firstAppApp"});
}

void
firstAppApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"firstAppApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
firstAppApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
firstAppApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
firstAppApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
firstAppApp__registerApps()
{
  firstAppApp::registerApps();
}

extern "C" void
firstAppApp__registerObjects(Factory & factory)
{
  firstAppApp::registerObjects(factory);
}

extern "C" void
firstAppApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  firstAppApp::associateSyntax(syntax, action_factory);
}

extern "C" void
firstAppApp__registerExecFlags(Factory & factory)
{
  firstAppApp::registerExecFlags(factory);
}
