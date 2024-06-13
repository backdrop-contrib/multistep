<?php

/**
 * Field handler that returns the completion status of a multistep node.
 */
class multistep_views_handler_field_status extends views_handler_field {
  function query() {
    $this->ensure_my_table();
    $this->query->add_field('node', 'type');
    $this->query->add_field('multistep', 'status');
    $this->query->add_groupby('nid');
  }

  function render($values) {
    if (!empty($values->multistep_status)) {
      return t('Incomplete');
    }
    if (is_multistep($values->node_type)) {
      return t('Complete');
    }
    return '';
  }
}
