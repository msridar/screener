<?php

function questionnaire_test_form($form, &$form_state, $node) {
  $form = array();
  $aids = array();
  $score = array();

  $questions = $node->field_questionnaire_questions[LANGUAGE_NONE];
  $questions_ids = array_column($questions, 'value');
  $qentities = entity_load('field_collection_item', $questions_ids);

  $form['qids'] = array('#type' => 'value', '#value' => $questions_ids);
  $form['test_nid'] = array('#type' => 'value', '#value' => $node->nid);
  $form['actions'] = array('#type' => 'actions');

  foreach ($qentities as $key => $value) {
    $score[$key] = $value->field_question_score[LANGUAGE_NONE][0]['value'];
    $choices_ids = array_column($value->field_questionnaire_options_pack[LANGUAGE_NONE], 'value');
    $choiceEntities = entity_load('field_collection_item', $choices_ids);
    $choices = array();

    foreach ($choiceEntities as $cKey => $cValue) {
      $choices[$cKey] = $cValue->field_questionnaire_option[LANGUAGE_NONE][0]['value'];
      if ($cValue->field_option_isvalid[LANGUAGE_NONE][0]['value']) {
        $aids[$key] = $cKey;
      }
    }

    $form['qContainer' . $key] = array(
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
      '#collapsed' => FALSE
    );

    $form['qContainer' . $key]['q'.$key] = array(
      '#type' => 'radios',
      '#title' => $value->field_questionnaire_question[LANGUAGE_NONE][0]['value'] . " ?",
      '#options' => $choices,
      '#required' => TRUE
    );

  };

  $form['aids'] = array('#type' => 'value', '#value' => $aids);
  $form['scores'] = array('#type' => 'value', '#value' => $score);

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Complete Test'),
    '#attributes' => array(
      'class' => array('btn btn-primary')
    )
  );
  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'quiz/' . $node->nid, array('attributes' => array('class' => 'btn btn-default'))),
  );

  return $form;
}

function questionnaire_test_form_submit($form, &$form_state) {
  global $user;
  $values = $form_state['values'];
  $qids = $form_state['values']['qids'];
  $aids = $form_state['values']['aids'];
  $scores = $form_state['values']['scores'];
  $pass_percent_criteria = (array_sum($scores) / 2);
  $total_scores = [];

  foreach ($qids as $value) {
    if ($values['q' . $value]) {
      if ($aids[$value] == $values['q' . $value]) {
        $total_scores[] = $scores[$value];
      } else {
        $total_scores[] = 0;
      }
    }
  }
  $total_scores = array_sum($total_scores);
  if ($total_scores >= $pass_percent_criteria) {
    $verdict = 'passed';
  } else {
    $verdict = 'failed';
  }

  $result_values = array(
    'type' => 'results',
    'uid' => $user->uid,
    'created' => time(),
    'changed' => time()
  );
  $result = entity_create('questionnaire_assesment', $result_values);
  $ewrapper = entity_metadata_wrapper('questionnaire_assesment', $result);
  $ewrapper->title->set('Results for ' . $form_state['values']['test_nid']);
  $ewrapper->field_questionnaire->set(intval($form_state['values']['test_nid']));
  $ewrapper->field_candidate->set(intval($user->uid));
  $ewrapper->field_total_score->set(intval($total_scores));
  $ewrapper->field_status->set('completed');
  $ewrapper->field_result->set($verdict);
  $result->save();

  drupal_set_message(t('You successfully completed your test. Please refer your profile for the results'));
  $form_state['redirect'] = 'quiz/' . $form_state['values']['test_nid'];
}
