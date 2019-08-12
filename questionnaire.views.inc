<?php
/**
 * @file
 * Views plugin handlers.
 */


/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function questionnaire_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'questionnaire'),
    ),
    'handlers' => array(
      'questionnaire_handler_take_test_field' => array(
        'parent' => 'views_handler_field',
      ),
      'questionnaire_handler_marksScored_field' => array(
        'parent' => 'views_handler_field',
      )
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function questionnaire_views_data() {
  $data = array();
  $data['questionnaire']['table']['group'] = t('Questionnaire');
  $data['questionnaire']['table']['join'] = array(
    '#global' => array(),
  );

  $data['questionnaire']['questionnaire_handler_take_test_field'] = array(
    'title' => t('Questionnaire Take Test field'),
    'help' => t('Questionnaire Take Test field'),
    'field' => array(
      'handler' => 'questionnaire_handler_take_test_field',
    ),
  );
  $data['questionnaire']['questionnaire_handler_marksScored_field'] = array(
    'title' => t('Questionnaire marks scored field'),
    'help' => t('Questionnaire marks scored field'),
    'field' => array(
      'handler' => 'questionnaire_handler_marksScored_field',
    ),
  );
  return $data;
}
