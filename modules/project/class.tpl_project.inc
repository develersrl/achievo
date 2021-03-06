<?php

useattrib("project.tpl_dependencyattrib");
useattrib("atktextattribute");
useattrib("atknumberattribute");
userelation("atkonetomanyrelation");
userelation("atkmanyboolrelation");

class tpl_project extends atkNode
{
  function tpl_project()
  {
    $this->atkNode("tpl_project",NF_EDITAFTERADD);

    $this->add(new atkNumberAttribute("id",AF_AUTOKEY));
    $this->add(new atkAttribute("name",AF_UNIQUE|AF_SEARCHABLE|AF_OBLIGATORY, 50));
    $this->add(new atkTextAttribute("description",TEXT_LARGE, AF_HIDE_ADD));
    $this->add(new atkOneToManyRelation("tpl_project_phase","project.tpl_project_phase","projectid", AF_HIDE_ADD|AF_HIDE_LIST|AF_NOSORT));
    $this->add(new tpl_dependencyAttribute("dependencies",AF_HIDE_ADD|AF_HIDE_LIST|AF_BLANKLABEL));
    $rel = &$this->add(new atkManyBoolRelation("documenttypes", "docmanager.projecttpl_doctype", "docmanager.documenttype", AF_HIDE_LIST|AF_HIDE_ADD));
    $rel->setLocalKey("projecttpl_id");
    $rel->setRemoteKey("documenttype_id");
    $rel->setDestinationFilter("master='project.project'");

    $this->setTable("tpl_project","tpl_project");
    $this->setOrder("name");
  }

  function descriptor_def()
  {
    return "[name]";
  }

  function initial_values()
  {
    return array("status"=>"active");
  }
}
?>