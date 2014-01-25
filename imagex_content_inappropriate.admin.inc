<?php 
/**
 * @file
 * Administration page callbacks for the for the ImageX Inappropriate Content module.
 */
 
/**
 * Form builder. Configure Content Inappropriate flags.
 * @ingroup forms
 * @see system_settings_form().
 */
function imagex_content_inappropriate_admin_settings() {
  foreach (imagex_content_inappropriate_valid_entities() as $entity_type) {   
    $form[$entity_type] = array(
      '#type' => 'fieldset',
      '#title' => $entity_type,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $entity_bundle = false;
    $entity_info = entity_get_info($entity_type);
    foreach ($entity_info['bundles'] as $bundle_name => $bundle_info) {     
      $entity_bundle[] = $bundle_info['label'];
    }
    $bundles[$entity_type] = $entity_bundle;
    $form[$entity_type]['imagex_content_inappropriate_entity_type_' . $entity_type] = array( 
      '#type' => 'checkboxes',
      '#title' => '',
      '#options' => $bundles[$entity_type],
      '#description' => t('By checking these boxes, you will be allowing the corresponding bundles to be flagged as Inappropriate Content.')
    );
  }
  $form['#submit'][] = 'imagex_content_inappropriate_admin_settings_submit';
  return system_settings_form($form);
}