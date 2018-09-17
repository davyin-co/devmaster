<?php

use Symfony\Component\Process\Process;
use GitWrapper\GitWrapper;
use GitWrapper\GitWorkingCopy;
use GitWrapper\GitException;

/**
 * Implementation of hook_drush_command().
 * Provides provision commands for all devshop tasks.
 */
function aegir_features_drush_command()
{
  $items['provision-features_update'] = array(
    'description' => 'Runs drush features-update-all.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'options' => array(
      'features' => 'The list of features to update.',
      'revert' => 'Whether or not to revert the features afterwards.',
    ),
  );
  return $items;
}

/**
 * Implements the provision-fua command.
 */
function drush_aegir_features_provision_features_update() {
  drush_errors_on();

  $features = trim(drush_get_option('features', ''));
  $revert = drush_get_option('revert', FALSE);

  // If features were specified...
  if (!empty($features)) {
    provision_backend_invoke(d()->name, "features-update", array($features));
  }
  else {
    provision_backend_invoke(d()->name, "features-update-all");
  }

  // Revert force revert the features if the user asked.
  if ($revert) {
    if (!empty($features)) {
      provision_backend_invoke(d()->name, "features-revert", array($features), array('force' => 1));
    }
    else {
      provision_backend_invoke(d()->name, "features-revert-all", array(), array('force' => 1));
    }
  }
}
