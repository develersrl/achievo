<?php
  /**
   * This file is part of the Achievo ATK distribution.
   * Detailed copyright and licensing information can be found
   * in the doc/COPYRIGHT and doc/LICENSE files which should be
   * included in the distribution.
   *
   * @package atk
   * @subpackage fixture
   *
   * @copyright (c)2007 Ibuildings.nl BV
   * @license http://www.achievo.org/atk/licensing ATK Open Source License
   *
   * @version $Revision: 1.3 $
   * $Id: class.atkyamlfixtureloader.inc,v 1.3 2007/08/30 00:01:39 ivo Exp $
   */

  /**
   * YAML fixture loader. Loads YAML fixtures. In the YAML
   * fixture you can optionally use PHP code to output the fixtures
   * PHP code should be enclosed in PHP tags. Script has full access
   * to all of ATK. Scripts output will be interpreted as YAML.
   *
   * @author Peter C. Verhage <peter@ibuildings.nl>
   * @package atk
   * @subpackage fixture
   */
  class atkYAMLFixtureLoader extends atkAbstractFixtureLoader
  {
    /**
     * Loads and returns the fixture data from the given file.
     *
     * @param string $path fixture file path
     * @return array fixture data
     */
    function load($path)
    {
      $contents = file_get_contents($path);
      $contents = $this->parse($contents);
    	atkimport('atk.utils.atkyaml');
      $data = atkYAML::load($contents);
      return $data;
    }
  }