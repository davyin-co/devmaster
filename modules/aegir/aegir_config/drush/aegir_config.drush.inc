<?php

/**
 * @file
 * Provision/Drush hooks for the aegir_config module.
 */

/**
 * Implementation of hook_drush_command().
 */
function aegir_config_drush_command() {
  $items['provision-config_export'] = array(
    'description' => 'Run drush config-export.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  $items['provision-config_import'] = array(
    'description' => 'Run drush config-import.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );
  return $items;
}

/**
 * Implements the provision-config_export command.
 */
function drush_aegir_config_provision_config_export() {
  drush_errors_on();
  if (drush_drupal_major_version(d()->root) == 8) {
    $destination = drush_get_option('destination', '');
    provision_backend_invoke(d()->name, 'config-export', array(), array('destination' => $destination));
  }
  else {
    drush_set_error('DRUSH_APPLICATION_ERROR', dt('Not a Drupal 8 site.  Command config-export not available.'));
  }
}

/**
 * Implements the provision-config_import command.
 */
function drush_aegir_config_provision_config_import() {
  drush_errors_on();
  if (drush_drupal_major_version(d()->root) == 8) {
    $source = drush_get_option('source', '');
    provision_backend_invoke(d()->name, 'config-import', array(), array('source' => $source));
  }
  else {
    drush_set_error('DRUSH_APPLICATION_ERROR', dt('Not a Drupal 8 site.  Command config-import not available.'));
  }
}