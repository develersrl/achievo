<?php

/**
 * Module Reports
 * Class reportorganization
 *
 * This class makes it possible to view all kind of information about a organization.
 *
 * $Id$
 * @author L. Willems  <lineke@ibuildings.nl>
 * @version $Revision$
 *
 */

userelation("atkonetomanyrelation");

class reportorganization extends atkNode
{
  function reportorganization()
  {
    global $g_sessionManager;
    $this->atkNode("reportorganization", NF_NO_SEARCH);

    $this->add(new atkAttribute("id" ,AF_HIDE|AF_AUTO_INCREMENT|AF_PRIMARY));
    $this->add(new atkOneToManyRelation("contactperson","organization.contact","company",AF_HIDE_LIST), "contact_appointments");
    $this->add(new atkOneToManyRelation("contracts","organization.contracts","customer",AF_HIDE_LIST), "contract");
    $this->add(new atkOneToManyRelation("projects","organization.project_organization","organizationid",AF_HIDE_LIST), "project");
    $this->addFilter("organization.id =".$g_sessionManager->stackVar("organizationid"));

    $this->setTable("organization", "organization");
  }
}
?>