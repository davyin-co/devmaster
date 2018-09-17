<?php
/**
 * @file
 *   Expose the extra tasks feature to hostmaster.
 */

/**
 * Implements hook_hosting_feature().
 */
function aegir_config_hosting_feature() {
  $features['aegir_config'] = array(
    'title' => t('Config Management'),
    'description' => t("Tasks that assist in Drupal 8 config management"),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'aegir_config',
    'group' => 'advanced',
  );
  return $features;
}

