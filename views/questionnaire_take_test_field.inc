<?php

/**
 * @file
 * Definition of goarn_lms_handler_lmscourses_field
 */

/**
 * Provides a custom views field.
 */
class questionnaire_handler_take_test_field extends views_handler_field {

  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = array(
      'table' => 'node',
      'field' => 'type',
    );
    $this->additional_fields['nid'] = array(
      'table' => 'node',
      'field' => 'nid',
    );
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($data) {
    global $user;
    if ($this->get_value($data, 'type') == 'questionnaire') {
      if (count(array_intersect($user->roles, array('supervisor', 'owner', 'administrator'))) <= 0) {
        return l('Take Test', '/quiz/'.$this->get_value($data, 'nid'));
      }
    }
    return "";
  }
}

/**
 * Provides a custom views field.
 */
class questionnaire_handler_marksScored_field extends views_handler_field {

  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['field_total_score'] = array(
      'table' => 'field_data_field_total_score',
      'field' => 'field_total_score_value',
    );
    $this->additional_fields['field_questionnaire'] = array(
      'table' => 'field_data_field_questionnaire',
      'field' => 'field_questionnaire_target_id',
    );
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($data) {
    $score = array();
    $total_score = "";
    $scored_mark = $this->get_value($data, 'field_total_score');
    $questionnaire = $this->get_value($data, 'field_questionnaire');
    $q_node = node_load($questionnaire);
    $questions_ids = $q_node->field_questionnaire_questions[LANGUAGE_NONE];
    $questions = array_column($questions_ids, 'value');
    $questions_coll = entity_load('field_collection_item', $questions);

    foreach ($questions_coll as $value) {
      $score[] = $value->field_question_score[LANGUAGE_NONE][0]['value'];
    }
    $total_score = array_sum($score);
    return $scored_mark . " / " . $total_score;
  }
}
