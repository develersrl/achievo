<?php

/**
 * Module Organization
 * Class organization
 *
 * This class makes it possible to add, edit and delete organizations.
 *
 * $Id: class.organization.inc 5467 2009-03-01 18:42:59Z sandy $
 * @author L. Willems  <lineke@ibuildings.nl>
 * @version $Revision: 5467 $
 *
 */


useattrib("atktextattribute");
useattrib("atkdummyattribute");
useattrib("atknumberattribute");
useattrib("atkparserattribute");
useattrib("atkdocumentattribute");
useattrib("atklistattribute");
userelation("atkonetomanyrelation");
userelation("atkmanytoonerelation");
useattrib("atkcreatedbyattribute");
useattrib("atkCreateStampAttribute");
useattrib("atkupdatedbyattribute");
useattrib("atkupdatestampattribute");
useattrib("atktabbedpane");

class organization extends atkNode
{
  function organization()
  {
    $this->atkNode("organization", NF_EDITAFTERADD|NF_EXPORT);
    $listener = &atknew("modules.crm.listeners.eventlistener");
    $this->addListener($listener);

    $this->add(new atkNumberAttribute("id" ,AF_AUTOKEY));
    $this->add(new atkAttribute("organizationcode", AF_SEARCHABLE));
    $this->add(new atkAttribute("name",AF_SEARCHABLE|AF_OBLIGATORY, 100));
    $this->add(new atkListAttribute("type", array("customer", "supplier"), "", AF_HIDE_LIST));
    //$this->add(new atkDummyAttribute("visitheader", "<b>".atktext("organization_visitaddress", "organization")."</b>", AF_HIDE_LIST|AF_HIDE_ADD|AF_NO_LABEL));

    // TODO FIXME: in future version 1.1, the fields for address should be renamed to visit_*.
    // But in the 1.0 branch, we want to remain backwardscompatible.
    $this->add(new atkAttribute("visit_address", AF_SEARCHABLE|AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("visit_address2", AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("visit_zipcode", AF_HIDE_LIST|AF_HIDE_ADD, 20));
    $this->add(new atkAttribute("visit_city", AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("visit_state", AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("visit_country", AF_HIDE_LIST|AF_HIDE_ADD, 100));

    //$this->add(new atkDummyAttribute("mailheader", "<b>".atktext("organization_mailaddress", "organization")."</b>", AF_HIDE_LIST|AF_HIDE_ADD|AF_NO_LABEL));
    $this->add(new atkAttribute("mail_address", AF_SEARCHABLE|AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("mail_address2", AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("mail_zipcode", AF_HIDE_LIST|AF_HIDE_ADD, 20));
    $this->add(new atkAttribute("mail_city", AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("mail_state", AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("mail_country", AF_HIDE_LIST|AF_HIDE_ADD, 100));

    //$this->add(new atkDummyAttribute("invoiceheader", "<b>".atktext("organization_invoiceaddress", "organization")."</b>", AF_HIDE_LIST|AF_HIDE_ADD|AF_NO_LABEL));
    $this->add(new atkAttribute("invoice_address", AF_SEARCHABLE|AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("invoice_address2", AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("invoice_zipcode", AF_HIDE_LIST|AF_HIDE_ADD, 20));
    $this->add(new atkAttribute("invoice_city", AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("invoice_state", AF_HIDE_LIST|AF_HIDE_ADD, 100));
    $this->add(new atkAttribute("invoice_country", AF_HIDE_LIST|AF_HIDE_ADD, 100));

    $this->add(new atkTabbedPane('address_tab',array('visit'=>array('visit_address','visit_address2','visit_zipcode','visit_city','visit_state','visit_country'),
                                                     'mail'=>array('mail_address','mail_address2','mail_zipcode','mail_city','mail_state','mail_country'),
                                                     'invoice'=>array('invoice_address','invoice_address2','invoice_zipcode','invoice_city','invoice_state','invoice_country')),AF_HIDE_ADD|AF_HIDE_LIST));

    $this->add(new atkDummyAttribute("divider", "<br>", AF_HIDE_LIST|AF_HIDE_ADD|AF_NO_LABEL));
    $this->add(new atkAttribute("phone",AF_SEARCHABLE|AF_HIDE_ADD, 20));
    $this->add(new atkAttribute("fax",AF_SEARCHABLE|AF_HIDE_ADD, 20));
    $this->add(new atkAttribute("email",AF_SEARCHABLE|AF_HIDE_ADD, 50));
    $this->add(new atkAttribute("website",AF_HIDE_ADD|AF_HIDE_LIST, 100));
    $this->add(new atkAttribute("bankaccount", AF_HIDE_LIST|AF_HIDE_ADD, 30));
    $this->add(new atkAttribute("bankaccount2", AF_HIDE_LIST|AF_HIDE_ADD, 30));
    $this->add(new atkAttribute("bankaccount3", AF_HIDE_LIST|AF_HIDE_ADD, 30));
    $this->add(new atkAttribute("bankaccount4", AF_HIDE_LIST|AF_HIDE_ADD, 30));
    $this->add(new atkAttribute("vatnumber", AF_HIDE_LIST|AF_HIDE_ADD, 25));
    $this->add(new atkAttribute("debtornumber", AF_HIDE_LIST|AF_HIDE_ADD, 30));
    $this->add(new atkManyToOneRelation("member_of","organization.organization",AF_HIDE_LIST|AF_LARGE|AF_HIDE_ADD));
    $this->add(new atkManyToOneRelation("status","crm.organization_status",AF_HIDE_LIST|AF_HIDE_ADD));
    $this->add(new atkManyToOneRelation("source","crm.source",AF_HIDE_LIST|AF_HIDE_ADD));
    $this->add(new atkManyToOneRelation("industry","crm.industry",AF_HIDE_LIST|AF_HIDE_ADD));
    $this->add(new atkNumberAttribute("employees",AF_HIDE_LIST|AF_HIDE_ADD,5));
    $this->add(new atkAttribute("revenue",AF_HIDE_LIST|AF_HIDE_ADD,5));
    $this->add(new atkManyToOneRelation("rate","crm.rate",AF_HIDE_LIST|AF_READONLY|AF_HIDE_ADD));
    $this->add(new atkManyToOneRelation("assigned_to","employee.employee",AF_SEARCHABLE|AF_HIDE_ADD|AF_HIDE_LIST));
    $this->add(new atkTextAttribute("remark", TEXT_LARGE, AF_HIDE_LIST|AF_HIDE_ADD));
    $this->add(new atkOneToManyRelation("contactperson","organization.contact","company",AF_HIDE_LIST),"contacts");
    $this->add(new atkTabbedPane("project_subtabs",array("activeprojects"=>array("projects"),"archivedprojects"=>array("archivedprojects")),AF_HIDE_ADD|AF_NO_LABEL),"project");

    $this->add(new atkTabbedPane('contract_subtabs', array('activecontracts'=>array('contracts'),'archivedcontracts'=>array('archivedcontracts')), AF_HIDE_LIST|AF_NO_LABEL|AF_HIDE_ADD), 'contracts');
    $activeContracts = &$this->add(new atkOneToManyRelation("contracts","organization.contracts","customer",AF_HIDE_LIST));
    $activeContracts->addDestinationFilter("contract.status='active'");
    $archivedContracts = &$this->add(new atkOneToManyRelation("archivedcontracts","organization.contracts","customer",AF_HIDE_LIST));
    $archivedContracts->addDestinationFilter("contract.status!='active'");

    $projectRelatie = new atkOneToManyRelation("projects", "project.project", "customer",AF_HIDE_LIST|AF_HIDE_ADD);
    $projectRelatie->addDestinationFilter("project.status='active'");
    $this->add($projectRelatie);
    $this->add(new atkParserAttribute("archivedprojects", "see_below", AF_HIDE_LIST|AF_HIDE_ADD));
    //$this->add(new atkTabbedPane("extra_subtabs",array("quotations"=>array("quotations")),AF_HIDE_ADD|AF_NO_LABEL),"extra");
    $this->add(new atkOneToManyRelation("former_names","crm.former_name","account",AF_HIDE_LIST|AF_HIDE_ADD),"extra");
    $this->add(new atkOneToManyRelation("relation","crm.organization_relation","account",AF_HIDE_LIST|AF_HIDE_ADD),"extra");
    $this->add(new atkOneToManyRelation("quotations","quotation.quotation","organization_id",AF_HIDE_LIST),"extra");
    $this->add(new atkParserAttribute("vcard", href("?atkaction=vcard&id=[id]", atktext("vcard"), SESSION_NESTED), AF_NO_LABEL|AF_HIDE_ADD), NULL, 10000);

    $this->add(new atkDocumentAttribute("document",AF_HIDE_LIST));

    $this->add(new atkCreatedByAttribute("created_by",AF_HIDE_LIST),"history");
    $this->add(new atkCreateStampAttribute("created_on",AF_HIDE_LIST),"history");
    $this->add(new atkUpdatedByAttribute("last_modified_by",AF_HIDE_LIST),"history");
    $this->add(new atkUpdateStampAttribute("last_modified_on",AF_HIDE_LIST),"history");


    $this->m_securityMap["vcard"] = "view";
    $this->m_securityMap["export"] = "view";

    $this->setTable("organization", "organization");
    $this->setOrder("organization.name");
    $this->setIndex("name");
    $this->setDescriptorTemplate('[name] [visit_city] ([organizationcode])');
  }

  function descriptor($rec="")
  {
    if(!empty($rec))
    {
      $tpl = '[name]';
      if($rec['visit_city']!='') $tpl.=', [visit_city]';
      if($rec['organizationcode']!='') $tpl.=' ([organizationcode])';
      $this->setDescriptorTemplate($tpl);
    }
    return parent::descriptor($rec);
  }

  function descriptorFields()
  {
    return array("name", "visit_city", "organizationcode");
  }

  /**
   * Determines the current view to be used (active or archive)
   *
   * @return string Current view mode ("all", "customer" or "supplier")
   */
  function getView()
  {
    // We use the session manager to retrieve the view.
    // this way, when paging, or when returning from an
    // edit screen etc., the system will have remembered
    // if we were viewing active records or the archive.
    $sessionManager = &atkGetSessionManager();
    $view = $sessionManager->pageVar("view");
    if (!in_array($view, array("all", "customer", "supplier")))
      $view = "all";
    return $view;
  }

  /**
   * Admin action handler override to implement archive and active view modes
   *
   * This function overrides the default adminHandlers action_admin, in
   * order to add our filtering logic to the admin action. This is done to
   * implement the archive and active view modes
   *
   * @param atkActionHandler &$handler Default admin actionhandler
   * @return atkAdminHandler Default admin action handler
   */
  function action_admin(&$handler)
  {
    // Add the filtering logic to the admin screen
    $view = $this->getView();
    if ($view != "all")
      $this->addFilter("organization.type='$view'");

    // Call the default adminHandler action_admin so the default action will be undertaken.
    return $handler->action_admin();
  }

  /**
   * Add html interface for switching to archive and active in user interface footer
   *
   * In this function we provide the user with a way to switch the view by
   * adding a link to the view the user is not in.
   *
   * @return string HTML Code fore the link to the other view
   */
  function adminHeader()
  {
    $result = "<br>" . $this->text("view"). ":";
    foreach (array("all", "customer", "supplier") as $filter)
      $result .= " " . href(dispatch_url("organization.organization", "admin", array("view"=>$filter)), $this->text($filter));
    $result .= "<br><br>";
    return $result;
  }

  function getExportAttributeGroup($attributename)
  {
    if (strpos($attributename, "visit_") === 0) return "organization_visitaddress";
    if (strpos($attributename, "mail_") === 0) return "organization_mailaddress";
    if (strpos($attributename, "invoice_") === 0) return "organization_invoiceaddress";
  }

  function action_export(&$handler)
  {
    // Some attributes are not usefull in exports
    foreach(array("contactperson", "contracts", 'archivedcontracts', "projects", "archivedprojects", "vcard", "document") as $attrname)
    {
      $attr = &$this->getAttribute($attrname);
      $attr->addFlag(AF_HIDE);
    }

    // Let the export handler do it's work
    return $handler->action_export();
  }

  function email_display($record, $mode)
  {
    $email = $record["email"];
    if (!in_array($mode, array("csv", "plain")) && $email!='')
      $email = sprintf('<a href="mailto:%1$s">%1$s</a>', $email);
    return $email;
  }

   function website_display($record, $mode)
  {
    $website = $record["website"];
    if (!in_array($mode, array("csv", "plain")) && $website!='')
      $website = '<a href="http://'.$website.'" target="_blank">'.$website.'</a>';
    return $website;
  }

  function website_edit($record, $mode)
  {
     $attr = &$this->getAttribute("website");
     $org = $attr->edit($record, $mode);
     return "http://".$org;
  }

  function archivedprojects_edit($record)
  {
    return $this->showProjects($record,"relation","archived");
  }

  function archivedprojects_display($record)
  {
    return $this->showProjects($record,"view","archived");
  }

  function showProjects($record, $mode,$status="active")
  {
    $projectnode = &atkGetNode("project.project");
    $projectnode->m_fuzzyFilters=array("project.status='$status'");
    $recs = $projectnode->selectDb("customer = ".$record["id"], "", "", $projectnode->m_listExcludes);
    if (count($recs)>0)
    {
      $rl = &atknew("atk.recordlist.atkrecordlist");
      return $rl->render($projectnode, $recs, $projectnode->defaultActions($mode), RL_NO_SEARCH|RL_NO_SORT);
    }
    return atktext("none");
  }

  function postDelete($record)
  {
    $eventlog = &atkGetNode("crm.eventlog");
    $eventlog->delete_event_history($this->atknodetype(),$record["atkprimkey"]);
    return true;
  }

  function action_vcard(&$handler)
  {
    // Get the record
    $id = atkArrayNvl($this->m_postvars, "id");
    $organizations = $this->selectDb("organization.id='".$id."'", "", "", "", "", "view");

    // Create the vcard
    include_once(moduleDir("utils")."vcard.php");
    $vcard = new vCard();
    $this->assignVcard($vcard, $organizations[0]);

    // Output the vcard and stop further script execution
    $vcard->outputVCard();
    exit;
  }

  function assignVcard(&$vcard, $record, $isperson = false)
  {
    $vcard->setFormattedName($record["name"]);
    $vcard->setProperty("ORG", $record["name"]);
    $vcard->setAddress("", "", $record["visit_address"], $record["visit_city"], $record["visit_state"], $record["visit_zipcode"], $record["visit_country"], "WORK");
    $vcard->setAddress("", "", $record["mail_address"], $record["mail_city"], $record["mail_state"], $record["mail_zipcode"], $record["mail_country"], "POSTAL");
    $vcard->setPhoneNumber($record["phone"], "WORK;VOICE");
    $vcard->setPhoneNumber($record["fax"], "WORK;FAX");
    $vcard->setEmail($record["email"]);
    $vcard->setURL("http://" . $record["website"], "WORK");
    $vcard->setNote($record["remark"]);
  }

}

?>
