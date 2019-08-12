<?php

/**
 * Implements hook_views_default_views().
 */
function questionnaire_views_default_views() {
  $view = new view();
  $view->name = 'my_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_questionnaire_assesment';
  $view->human_name = 'My Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_candidate_target_id']['id'] = 'field_candidate_target_id';
  $handler->display->display_options['relationships']['field_candidate_target_id']['table'] = 'field_data_field_candidate';
  $handler->display->display_options['relationships']['field_candidate_target_id']['field'] = 'field_candidate_target_id';
  /* Field: Questionnaire Assesment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_questionnaire_assesment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Questionnaire Assesment: Questionnaire */
  $handler->display->display_options['fields']['field_questionnaire']['id'] = 'field_questionnaire';
  $handler->display->display_options['fields']['field_questionnaire']['table'] = 'field_data_field_questionnaire';
  $handler->display->display_options['fields']['field_questionnaire']['field'] = 'field_questionnaire';
  $handler->display->display_options['fields']['field_questionnaire']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Questionnaire Assesment: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Questionnaire: Questionnaire marks scored field */
  $handler->display->display_options['fields']['questionnaire_handler_marksScored_field']['id'] = 'questionnaire_handler_marksScored_field';
  $handler->display->display_options['fields']['questionnaire_handler_marksScored_field']['table'] = 'questionnaire';
  $handler->display->display_options['fields']['questionnaire_handler_marksScored_field']['field'] = 'questionnaire_handler_marksScored_field';
  $handler->display->display_options['fields']['questionnaire_handler_marksScored_field']['label'] = 'Scored';
  /* Field: Questionnaire Assesment: Result */
  $handler->display->display_options['fields']['field_result']['id'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['table'] = 'field_data_field_result';
  $handler->display->display_options['fields']['field_result']['field'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_result']['alter']['text'] = '<h4><span class=\'label label-[field_result-value]\'>[field_result-value]</span></h4>';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_candidate_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Questionnaire Assesment: questionnaire_assesment type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_questionnaire_assesment';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'results' => 'results',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'node_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_questionnaire_assesment';
  $view->human_name = 'Node Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Node - Results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_questionnaire_target_id']['id'] = 'field_questionnaire_target_id';
  $handler->display->display_options['relationships']['field_questionnaire_target_id']['table'] = 'field_data_field_questionnaire';
  $handler->display->display_options['relationships']['field_questionnaire_target_id']['field'] = 'field_questionnaire_target_id';
  /* Field: Questionnaire Assesment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_questionnaire_assesment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Questionnaire Assesment: Candidate */
  $handler->display->display_options['fields']['field_candidate']['id'] = 'field_candidate';
  $handler->display->display_options['fields']['field_candidate']['table'] = 'field_data_field_candidate';
  $handler->display->display_options['fields']['field_candidate']['field'] = 'field_candidate';
  $handler->display->display_options['fields']['field_candidate']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  /* Field: Questionnaire: Questionnaire marks scored field */
  $handler->display->display_options['fields']['questionnaire_handler_marksScored_field']['id'] = 'questionnaire_handler_marksScored_field';
  $handler->display->display_options['fields']['questionnaire_handler_marksScored_field']['table'] = 'questionnaire';
  $handler->display->display_options['fields']['questionnaire_handler_marksScored_field']['field'] = 'questionnaire_handler_marksScored_field';
  $handler->display->display_options['fields']['questionnaire_handler_marksScored_field']['label'] = 'Scored';
  /* Field: Questionnaire Assesment: Status */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  /* Field: Questionnaire Assesment: Result */
  $handler->display->display_options['fields']['field_result']['id'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['table'] = 'field_data_field_result';
  $handler->display->display_options['fields']['field_result']['field'] = 'field_result';
  $handler->display->display_options['fields']['field_result']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_result']['alter']['text'] = '<h4><span class=\'label label-[field_result-value]\'>[field_result-value]</span></h4>';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_questionnaire_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = '%1 - Results';
  $handler->display->display_options['arguments']['nid']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'access denied';
  /* Filter criterion: Questionnaire Assesment: questionnaire_assesment type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_questionnaire_assesment';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'results' => 'results',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/results';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Results';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Results';
  $handler->display->display_options['tab_options']['weight'] = '0';

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'results_management';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_questionnaire_assesment';
  $view->human_name = 'Results Management';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Results Management';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_questionnaire' => 'field_questionnaire',
    'edit_link' => 'edit_link',
    'delete_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_questionnaire' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Questionnaire Assesment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_questionnaire_assesment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Questionnaire Assesment: Questionnaire */
  $handler->display->display_options['fields']['field_questionnaire']['id'] = 'field_questionnaire';
  $handler->display->display_options['fields']['field_questionnaire']['table'] = 'field_data_field_questionnaire';
  $handler->display->display_options['fields']['field_questionnaire']['field'] = 'field_questionnaire';
  $handler->display->display_options['fields']['field_questionnaire']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  /* Field: Questionnaire Assesment: Candidate */
  $handler->display->display_options['fields']['field_candidate']['id'] = 'field_candidate';
  $handler->display->display_options['fields']['field_candidate']['table'] = 'field_data_field_candidate';
  $handler->display->display_options['fields']['field_candidate']['field'] = 'field_candidate';
  $handler->display->display_options['fields']['field_candidate']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  /* Field: Questionnaire Assesment: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_questionnaire_assesment';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = 'Edit';
  /* Field: Questionnaire Assesment: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_questionnaire_assesment';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = 'Delete';
  /* Filter criterion: Questionnaire Assesment: questionnaire_assesment type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_questionnaire_assesment';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'results' => 'results',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/structure/entity-type/questionnaire_assesment/results/results-management';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Results Management';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'tests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Tests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tests';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'view_node' => 'questionnaire_handler_take_test_field',
    'questionnaire_handler_take_test_field' => 'questionnaire_handler_take_test_field',
    'edit_node' => 'questionnaire_handler_take_test_field',
    'delete_node' => 'questionnaire_handler_take_test_field',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '  | ',
      'empty_column' => 0,
    ),
    'questionnaire_handler_take_test_field' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['path'] = 'quiz/[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Link to content */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Questionnaire: Questionnaire Take Test field */
  $handler->display->display_options['fields']['questionnaire_handler_take_test_field']['id'] = 'questionnaire_handler_take_test_field';
  $handler->display->display_options['fields']['questionnaire_handler_take_test_field']['table'] = 'questionnaire';
  $handler->display->display_options['fields']['questionnaire_handler_take_test_field']['field'] = 'questionnaire_handler_take_test_field';
  $handler->display->display_options['fields']['questionnaire_handler_take_test_field']['label'] = 'Operations';
  $handler->display->display_options['fields']['questionnaire_handler_take_test_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['questionnaire_handler_take_test_field']['empty'] = '[view_node] ';
  $handler->display->display_options['fields']['questionnaire_handler_take_test_field']['empty_zero'] = TRUE;
  /* Field: Content: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Link to delete content */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'questionnaire' => 'questionnaire',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tests';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Tests';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  $views[$view->name] = $view;

  return $views;
}
